#include <mpc_stabilizer/MpcStabilizer.h>
#include <MpcController.h>


mpcs::MpcStabilizer::MpcStabilizer(XBot::ModelInterface::ConstPtr model):
    _model(model),
    _cop_ref(0.0, 0.0),
    _mpc(new MpcControllerModelClass),
    _logger(XBot::MatLogger::getLogger("/tmp/mpc_stabilizer_log"))
{
    
    _plant = OpenMpC::dynamics::LtiDynamics::Integrator(3, 2);
    
    Eigen::Matrix2d eye; eye.setIdentity();
    Eigen::MatrixXd C(4,6);
    
    C << eye, eye*0.0, -eye,
         eye, eye*0.0, eye*0.0;
         
    _plant->addOutput("y", C);

    _mpc->initialize();
    
    _left_ft  = _model->chain("left_leg") .getForceTorque().begin()->second;
    _right_ft = _model->chain("right_leg").getForceTorque().begin()->second;

}

bool mpcs::MpcStabilizer::computeMPC(double period, Eigen::Vector2d& com_pos, Eigen::Vector2d& com_vel)
{
    
    /* Get measurements from model */
    Eigen::Vector3d com_pos_meas;
    _model->getCOM(com_pos_meas);

    /* Fill measurements and references */
    Eigen::Vector2d cop_meas = compute_cop();

    /* Get Eigen interfaces to matlab arrays */
    Eigen::Map<Eigen::Vector4d> ref(_mpc->MpcController_U.ref);
    Eigen::Map<Eigen::Vector2d> umax(_mpc->MpcController_U.umax);
    Eigen::Map<Eigen::Vector2d> umin(_mpc->MpcController_U.umin);
    Eigen::Map<Eigen::Vector4d> ymax(_mpc->MpcController_U.ymax);
    Eigen::Map<Eigen::Vector4d> ymin(_mpc->MpcController_U.ymin);
    Eigen::Map<Eigen::Vector4d> ymeas(_mpc->MpcController_U.ymeas);
    
    Eigen::Map<Eigen::Vector2d> mv(_mpc->MpcController_Y.mv);
    Eigen::Map<Eigen::Vector2d> dist(_mpc->MpcController_Y.dist);
    Eigen::Map<Eigen::VectorXd> x_est(_mpc->MpcController_Y.x_est, 8);
    
    ref << _cop_ref, 0.0, 0.0;
    umax.setConstant(1e10);
    umin = -umax;
    ymax << 1.5, 1.5, 1e10, 1e10;
    ymin = -ymax;
    ymeas << cop_meas, com_pos_meas.head<2>();
    

    _mpc->step();

    Eigen::VectorXd new_state = x_est;
    _plant->integrate(x_est, mv, period, new_state);
    
    com_pos = new_state.head<2>();
    com_vel = new_state.segment<2>(2);
    

    _logger->add("y", ymeas);
    _logger->add("cop_ref", _cop_ref);
    _logger->add("u", mv);
    _logger->add("x_est", x_est);
    _logger->add("dist_est", dist);

    _logger->add("ycop", cop_meas);
    _logger->add("ycom", com_pos_meas);
    
    Eigen::Vector6d wrench;
    _left_ft->getWrench(wrench);
    _logger->add("l_wrench", wrench);
    _right_ft->getWrench(wrench);
    _logger->add("r_wrench", wrench);
    
    

}


Eigen::Vector2d mpcs::MpcStabilizer::compute_local_cop(XBot::ForceTorqueSensor::ConstPtr ft)
{
    /* Left COP */
    Eigen::Affine3d w_T_ft;
    _model->getPose(ft->getSensorName(), w_T_ft);
    
    Eigen::Vector3d tau, f;
    ft->getForce(f);
    ft->getTorque(tau);
    
    Eigen::Vector2d l_cop = w_T_ft.translation().head<2>() + Eigen::Vector2d(-tau.y(), tau.x())/f.z();
    
    return l_cop;
    
}

Eigen::Vector2d mpcs::MpcStabilizer::compute_cop()
{
    Eigen::Vector2d cop_left  = compute_local_cop(_left_ft);
    Eigen::Vector2d cop_right = compute_local_cop(_right_ft);
    
    Eigen::Vector3d fl, fr;
    _left_ft->getForce(fl);
    _right_ft->getForce(fr);
    
    return (fl.z()*cop_left + fr.z()*cop_right)/(fl+fr).z();
}


void mpcs::MpcStabilizer::resetCopReference()
{
    Eigen::Affine3d l_sole, r_sole;
    _model->getPose("l_sole", l_sole);
    _model->getPose("r_sole", r_sole);
    
    _cop_ref = 0.5*(l_sole.translation() + r_sole.translation()).head<2>();
    
    std::cout << "Left foot pos: " << l_sole.translation().transpose() << std::endl;
    std::cout << "Right foot pos: " << r_sole.translation().transpose() << std::endl;
    std::cout << "Resetting cop reference to: " << _cop_ref.transpose() << std::endl;
}


mpcs::MpcStabilizer::~MpcStabilizer()
{
    _logger->flush();
}



