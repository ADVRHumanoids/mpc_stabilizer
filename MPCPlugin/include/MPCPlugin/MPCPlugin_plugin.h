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

#ifndef MPCPlugin_PLUGIN_H_
#define MPCPlugin_PLUGIN_H_

#include <XCM/XBotControlPlugin.h>
#include <mpc_stabilizer/MpcStabilizer.h>
#include <cartesian_interface/open_sot/OpenSotImpl.h>


namespace XBotPlugin {

/**
 * @brief MPCPlugin XBot RT Plugin
 *
 **/
class MPCPlugin : public XBot::XBotControlPlugin
{

public:

    virtual bool init_control_plugin(XBot::Handle::Ptr handle);

    virtual bool close();

    virtual void on_start(double time);

    virtual void on_stop(double time);
    
    virtual ~MPCPlugin();

protected:

    virtual void control_loop(double time, double period);

private:

    XBot::RobotInterface::Ptr _robot;
    XBot::ModelInterface::Ptr _model, _model_fb;

    double _start_time;

    Eigen::VectorXd _q0, _q, _qdot;
    Eigen::Vector3d _com_pos, _com_vel;

    XBot::MatLogger::Ptr _logger;
    
    XBot::Cartesian::CartesianInterface::Ptr _ci;
    mpcs::MpcStabilizer::Ptr _stab;

};

}

#endif // MPCPlugin_PLUGIN_H_
