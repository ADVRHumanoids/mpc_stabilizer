#include <mpc_stabilizer/MpcStabilizer.h>

mpcs::MpcStabilizer::MpcStabilizer(XBot::ModelInterface::ConstPtr model):
    _model(model),
    _cop_ref(0.0, 0.0),
    _logger(XBot::MatLogger::getLogger("/tmp/mpc_stabilizer_log"))
{
    rt_InitInfAndNaN(8U); // needed for unknown reason
    
    _plant = OpenMpC::dynamics::LtiDynamics::Integrator(3, 2);
    
    Eigen::Matrix2d eye; eye.setIdentity();
    Eigen::MatrixXd C(4,6);
    
    C << eye, eye*0.0, -eye,
         eye, eye*0.0, eye*0.0;
         
    _plant->addOutput("y", C);
    
    memset(&_mpcmovestate, 0, sizeof(_mpcmovestate));
    
    _left_ft  = _model->chain("left_leg") .getForceTorque().begin()->second;
    _right_ft = _model->chain("right_leg").getForceTorque().begin()->second;

}

bool mpcs::MpcStabilizer::computeMPC(Eigen::Vector2d& com_jerk)
{
    
    /* Get measurements from model */
    Eigen::Vector3d com_pos;
    _model->getCOM(com_pos);

    struct2_T r0; // measurements and references
    double u[2];  // control input
    struct7_T Info;

    /* Fill measurements and references */
    Eigen::Vector2d cop_meas = compute_cop();
    
    r0.signals.ym[0] = cop_meas.x();
    r0.signals.ym[1] = cop_meas.y();
    r0.signals.ym[2] = com_pos.x();
    r0.signals.ym[3] = com_pos.y();
        
    r0.signals.ref[0] = _cop_ref.x();
    r0.signals.ref[1] = _cop_ref.y();
    r0.signals.ref[2] = 0.0;
    r0.signals.ref[3] = 0.0;
    
    /* Solver MPC problem */
    mpcmoveCodeGeneration(&_mpcmovestate, &r0, u, &Info);
    
    /* Apply control input */
    Eigen::Map<Eigen::Vector2d> u_eigen(u);
    com_jerk = u_eigen;
    

    _logger->add("ycop", cop_meas);
    _logger->add("ycom", com_pos);
    _logger->add("u", u_eigen);
    
    Eigen::Map<Eigen::VectorXd> x_est(_mpcmovestate.Plant, 8);
    _logger->add("x_est", x_est);
    
    Eigen::Map<Eigen::VectorXd> dist_est(_mpcmovestate.Disturbance, 2);
    _logger->add("dist_est", dist_est);

}


Eigen::Vector2d mpcs::MpcStabilizer::compute_local_cop(XBot::ForceTorqueSensor::ConstPtr ft)
{
    /* Left COP */
    Eigen::Affine3d w_T_ft;
    _model->getPose(ft->getSensorName(), w_T_ft);
    
    Eigen::Vector3d tau, f;
    ft->getForce(f);
    ft->getTorque(tau);
    
    Eigen::Vector2d l_cop = w_T_ft.translation().head<2>() + Eigen::Vector2d(tau.y(), -tau.x())/f.z();
    
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






