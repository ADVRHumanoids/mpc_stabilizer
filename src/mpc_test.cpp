#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "mpcmoveCodeGeneration_terminate.h"
#include "mpcmoveCodeGeneration_initialize.h"
#include <XBotInterface/Logger.hpp>

#include <OpenMpC/dynamics/LtiDynamics.h>


int main(int argc, char ** argv){
  
    rt_InitInfAndNaN(8U); // needed for unknown reason

    
    auto logger = XBot::MatLogger::getLogger("/tmp/mpc_test_log");
    
    auto plant = OpenMpC::dynamics::LtiDynamics::Integrator(3, 2);
    Eigen::Matrix2d eye; eye.setIdentity();
    Eigen::MatrixXd C(4,6);
    
    C << eye, eye*0.0, -eye,
         eye, eye*0.0, eye*0.0;
         
    plant->addOutput("y", C);
    
    Eigen::VectorXd x(plant->getStateSize());
    x.setZero(x.size());
    
    
    int N_ITER = 1000;
    
    struct1_T mpcmovestate;
    memset(&mpcmovestate, 0, sizeof(mpcmovestate));
    
    
    double ts = 0.2;
    
    for(int i = 0; i < N_ITER; i++)
    {
     
        
        struct2_T r0; // measurements and references
        double u[2];  // control input
        struct7_T Info;

        /* Fill measurements and references */
        r0.signals.ref[0] = 0.7;
        r0.signals.ref[1] = 0.0;
        r0.signals.ref[2] = 0.0;
        r0.signals.ref[3] = 0.0;
        
        Eigen::VectorXd y_value;
        plant->getOutputValue("y", x, y_value); // same as C*x
        
        if(i > 500)
        {
            y_value[0] += 1.0;
//             mpcmovestate.Disturbance[0] = 1.0;
            
        }
        
        r0.signals.ym[0] = y_value[0];
        r0.signals.ym[1] = y_value[1];
        r0.signals.ym[2] = y_value[2];
        r0.signals.ym[3] = y_value[3];
        
        
        
        
        /* Solver MPC problem */
        mpcmoveCodeGeneration(&mpcmovestate, &r0, u, &Info);
        
        
        /* Apply control input */
        Eigen::Map<Eigen::Vector2d> u_eigen(u);
        
        plant->integrate(x, u_eigen, ts, x);

        logger->add("y", y_value);
        logger->add("u", u_eigen);
        logger->add("x", x);
        
        Eigen::Map<Eigen::VectorXd> x_est(mpcmovestate.Plant, 8);
        logger->add("x_est", x_est);
        
        Eigen::Map<Eigen::VectorXd> dist_est(mpcmovestate.Disturbance, 2);
        logger->add("dist_est", dist_est);
    }
    
    logger->flush();
    
  
  
  
}