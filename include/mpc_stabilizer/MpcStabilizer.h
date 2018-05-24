#ifndef __MPCSTABILIZER_H__
#define __MPCSTABILIZER_H__

#include <XBotInterface/ModelInterface.h>

#include <OpenMpC/dynamics/LtiDynamics.h>

class MpcControllerModelClass;

namespace mpcs {
 
    class MpcStabilizer {
        
    public:
        
        typedef std::shared_ptr<MpcStabilizer> Ptr;
        
        MpcStabilizer(XBot::ModelInterface::ConstPtr model);
        
        bool computeMPC(double period, Eigen::Vector2d& com_pos, Eigen::Vector2d& com_vel);
        
        void setCopReference(const Eigen::Vector2d& cop_ref);
        
        void resetCopReference();
        
        ~MpcStabilizer();
        
        
    private:
        
        typedef std::shared_ptr<MpcControllerModelClass> MpcControllerPtr;
        
        Eigen::Vector2d compute_cop();
        Eigen::Vector2d compute_local_cop(XBot::ForceTorqueSensor::ConstPtr ft);
        
        XBot::ModelInterface::ConstPtr _model;
        
        OpenMpC::dynamics::LtiDynamics::Ptr _plant;
        
        MpcControllerPtr _mpc;
        
        Eigen::Vector2d _cop_ref;
        
        XBot::ForceTorqueSensor::ConstPtr _left_ft, _right_ft;
        
        XBot::MatLogger::Ptr _logger;
        
        
        
    };
    
    
    
}


#endif



