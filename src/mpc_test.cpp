
#include <XBotInterface/Logger.hpp>
#include <MpcController.h>
#include <OpenMpC/dynamics/LtiDynamics.h>

#include <MpcController.h>

int main(int argc, char ** argv){
  
    auto logger = XBot::MatLogger::getLogger("/tmp/mpc_test_log");
    
    auto plant = OpenMpC::dynamics::LtiDynamics::Integrator(3, 2);
    Eigen::Matrix2d eye; eye.setIdentity();
    Eigen::MatrixXd C(4,6);
    const double h = 0.9, g = 9.8;
    
    
    C << eye, eye*0.0, -eye*h/g,
         eye, eye*0.0, eye*0.0;
         
    plant->addOutput("y", C);
    
    Eigen::VectorXd x(plant->getStateSize());
    x.setZero(x.size());
    
    
    int N_ITER = 10000;

    MpcControllerModelClass mpc;
    mpc.initialize();
    
    const double ts = 0.001;
    
    for(int i = 0; i < N_ITER; i++)
    {
        
        Eigen::Map<Eigen::Vector4d> ref(mpc.MpcController_U.ref);
        Eigen::Map<Eigen::Vector2d> umax(mpc.MpcController_U.umax);
        Eigen::Map<Eigen::Vector2d> umin(mpc.MpcController_U.umin);
        Eigen::Map<Eigen::Vector4d> ymax(mpc.MpcController_U.ymax);
        Eigen::Map<Eigen::Vector4d> ymin(mpc.MpcController_U.ymin);
        Eigen::Map<Eigen::Vector4d> ymeas(mpc.MpcController_U.ymeas);
        
        Eigen::Map<Eigen::Vector2d> mv(mpc.MpcController_Y.mv);
        Eigen::Map<Eigen::Vector2d> dist(mpc.MpcController_Y.dist);
        Eigen::Map<Eigen::VectorXd> x_est(mpc.MpcController_Y.x_est, 8);
        
        ref << 0.5, 0.0, 0.0, 0.0;
        umax.setConstant(1e10);
        umin = -umax;
        ymax << 1.5, 1.5, 1e10, 1e10;
        ymin = -ymax;
        ymeas = C*x;
        
        if(i > 3000)
        {
            ymeas[0] += 1.0;
        }
        
        mpc.step();

        plant->integrate(x, mv, ts, x);

        logger->add("y", ymeas);
        logger->add("u", mv);
        logger->add("x", x);
        logger->add("x_est", x_est);
        logger->add("dist_est", dist);
    }
    
    logger->flush();
    
  
  
  
}