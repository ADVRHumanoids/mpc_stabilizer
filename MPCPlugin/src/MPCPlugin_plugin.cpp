/*
 * Copyright (C) 2017 IIT-ADVR
 * Author:
 * email:
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <MPCPlugin_plugin.h>

/* Specify that the class XBotPlugin::MPCPlugin is a XBot RT plugin with name "MPCPlugin" */
REGISTER_XBOT_PLUGIN_(XBotPlugin::MPCPlugin)

namespace XBotPlugin {

bool MPCPlugin::init_control_plugin(XBot::Handle::Ptr handle)
{
    /* This function is called outside the real time loop, so we can
     * allocate memory on the heap, print stuff, ...
     * The RT plugin will be executed only if this init function returns true. */


    /* Save robot to a private member. */
    _robot = handle->getRobotInterface();
    _model = XBot::ModelInterface::getModel(handle->getPathToConfigFile());
    _model_fb = XBot::ModelInterface::getModel(handle->getPathToConfigFile());
    _stab = std::make_shared<mpcs::MpcStabilizer>(_model_fb);
    
    Eigen::VectorXd qhome;
    _model->getRobotState("home", qhome);
    _model->setJointPosition(qhome);
    _model->update();
    
    Eigen::Affine3d w_T_fb;
    _model->getPose("l_sole", w_T_fb);
    std::cout << w_T_fb.translation() << std::endl;
    _model->setFloatingBasePose(w_T_fb.inverse());
    _model->update();    
    _model->getPose("r_sole", w_T_fb);
    std::cout << w_T_fb.translation() << std::endl;
    
    YAML::Node yaml_file = YAML::LoadFile(handle->getPathToConfigFile());
    XBot::Cartesian::ProblemDescription ik_problem(yaml_file["CartesianInterface"]["problem_description"], _model);
    _ci = SoLib::getFactoryWithArgs<XBot::Cartesian::CartesianInterface>("CartesianOpenSot.so", 
                                                                         "OpenSotImpl", 
                                                                         _model, ik_problem);
    

    /* Initialize a logger which saves to the specified file. Remember that
     * the current date/time is always appended to the provided filename,
     * so that logs do not overwrite each other. */

    _logger = XBot::MatLogger::getLogger("/tmp/MPCPlugin_log");

    return true;


}

void MPCPlugin::on_start(double time)
{
    /* This function is called on plugin start, i.e. when the start command
     * is sent over the plugin switch port (e.g. 'rosservice call /MPCPlugin_switch true').
     * Since this function is called within the real-time loop, you should not perform
     * operations that are not rt-safe. */

    /* Save the plugin starting time to a class member */
    _robot->getMotorPosition(_q0);

    /* Save the robot starting config to a class member */
    _start_time = time;
    
//     _model->syncFrom(*_robot);
//     _model_fb->syncFrom(*_robot);
    
    Eigen::Affine3d w_T_fb;
    _model_fb->getPose("l_sole", w_T_fb);
   
    
    
//     _model->setFloatingBasePose(w_T_fb.inverse());
    _model_fb->setFloatingBasePose(w_T_fb.inverse());
    _model->update();
    _model_fb->update();
    
    _model->getCOM(_com_pos);
    _com_vel.setZero();
    
    std::cout << _com_pos << std::endl;
    
    _stab->resetCopReference();
    
    _ci->reset();
}

void MPCPlugin::on_stop(double time)
{
    /* This function is called on plugin stop, i.e. when the stop command
     * is sent over the plugin switch port (e.g. 'rosservice call /MPCPlugin_switch false').
     * Since this function is called within the real-time loop, you should not perform
     * operations that are not rt-safe. */
}


void MPCPlugin::control_loop(double time, double period)
{
    
    /* Get measurements */
    _model_fb->syncFrom(*_robot);
    
    /* Update MPC */
    Eigen::Vector2d com_pos_xy, com_vel_xy;
    _stab->computeMPC(period, com_pos_xy, com_vel_xy);
    
    /* IK update */
    _com_pos.head<2>() = com_pos_xy;
    _com_vel.head<2>() = com_vel_xy;
    _ci->setComPositionReference(_com_pos, _com_vel);
    
    _ci->update(time, period);
    
    _model->getJointPosition(_q);
    _model->getJointVelocity(_qdot);
    
    _q += period*_qdot;
    
    _model->setJointPosition(_q);
    _model->update();
    
    /* Send command */
    _robot->setReferenceFrom(*_model, XBot::Sync::Position, XBot::Sync::Velocity);
//     _robot->move();
    

}

bool MPCPlugin::close()
{
    /* This function is called exactly once, at the end of the experiment.
     * It can be used to do some clean-up, or to save logging data to disk. */

    /* Save logged data to disk */
    _logger->flush();

    return true;
}

MPCPlugin::~MPCPlugin()
{
  
}

}
