#ifndef __MPCSTABILIZER_H__
#define __MPCSTABILIZER_H__

#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "mpcmoveCodeGeneration_terminate.h"
#include "mpcmoveCodeGeneration_initialize.h"
#include <XBotInterface/ModelInterface.h>

#include <OpenMpC/dynamics/LtiDynamics.h>


namespace mpcs {
 
    class MpcStabilizer {
        
    public:
        
        MpcStabilizer(XBot::ModelInterface::ConstPtr model);
        
        bool computeMPC(Eigen::Vector2d& com_jerk);
        
        void setCopReference(const Eigen::Vector2d& cop_ref);
        
        
    private:
        
        typedef struct1_T MpcState;
        
        Eigen::Vector2d compute_cop();
        Eigen::Vector2d compute_local_cop(XBot::ForceTorqueSensor::ConstPtr ft);
        
        XBot::ModelInterface::ConstPtr _model;
        
        OpenMpC::dynamics::LtiDynamics::Ptr _plant;
        
        MpcState _mpcmovestate;
        
        Eigen::Vector2d _cop_ref;
        
        XBot::ForceTorqueSensor::ConstPtr _left_ft, _right_ft;
        
        XBot::MatLogger::Ptr _logger;
        
        
        
    };
    
    
    
}


#endif

