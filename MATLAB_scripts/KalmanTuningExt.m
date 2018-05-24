%% create MPC controller object with sample time
mpc_plant = setmpcsignals(p_ext, 'MV', [1;2], 'UD', [3;4], 'MO', [1:4]');
mpc2 = mpc(mpc_plant, 0.001);
%% specify prediction horizon
mpc2.PredictionHorizon = 30;
%% specify control horizon
mpc2.ControlHorizon = 5;
%% specify nominal values for inputs and outputs
mpc2.Model.Nominal.U = [0;0;0;0];
mpc2.Model.Nominal.Y = [0;0;0;0];
%% specify constraints for OV
mpc2.OV(1).Min = -1.5;
mpc2.OV(1).Max = 1.5;
%% specify overall adjustment factor applied to weights
beta = 0.81873;
%% specify weights
mpc2.Weights.MV = [0 0]*beta;
mpc2.Weights.MVRate = [0.1 0.1]/beta;
mpc2.Weights.OV = [10 1 0 0]*beta;
mpc2.Weights.ECR = 100000;
%% specify overall adjustment factor applied to estimation model gains
alpha = 50.0119;
%% adjust default input disturbance model gains
setindist(mpc2, 'model', getindist(mpc2)*alpha);
%% adjust default output disturbance model gains
setoutdist(mpc2, 'model', getoutdist(mpc2)*alpha);
%% adjust default measurement noise model gains
mpc2.Model.Noise = mpc2.Model.Noise/alpha;
%% specify simulation options
options = mpcsimopt();
options.UnmeasuredDisturbance = mpc1_UDSignal;
options.OutputNoise = mpc1_ODSignal_1;
options.RefLookAhead = 'off';
options.MDLookAhead = 'off';
options.Constraints = 'on';
options.OpenLoop = 'off';
%% run simulation
sim(mpc2, 101, mpc1_RefSignal_1, [], options);

%% get matrices

[L_kal, M_kal, A_kal, Cm_kal, Bu_kal, Bv_kal, Dvm_kal] = getEstimator(mpc2);
