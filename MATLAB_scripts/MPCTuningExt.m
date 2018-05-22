%% create MPC controller object with sample time
mpc_plant = setmpcsignals(p_ext, 'MV', [1;2], 'UD', [3;4], 'MO', [1:4]');
mpc1 = mpc(mpc_plant, 0.2);
%% specify prediction horizon
mpc1.PredictionHorizon = 30;
%% specify control horizon
mpc1.ControlHorizon = 5;
%% specify nominal values for inputs and outputs
mpc1.Model.Nominal.U = [0;0;0;0];
mpc1.Model.Nominal.Y = [0;0;0;0];
%% specify constraints for OV
mpc1.OV(1).Min = -1.5;
mpc1.OV(1).Max = 1.5;
%% specify overall adjustment factor applied to weights
beta = 0.81873;
%% specify weights
mpc1.Weights.MV = [0 0]*beta;
mpc1.Weights.MVRate = [0.1 0.1]/beta;
mpc1.Weights.OV = [10 1 0 0]*beta;
mpc1.Weights.ECR = 100000;
%% specify overall adjustment factor applied to estimation model gains
alpha = 5.0119;
%% adjust default input disturbance model gains
setindist(mpc1, 'model', getindist(mpc1)*alpha);
%% adjust default output disturbance model gains
setoutdist(mpc1, 'model', getoutdist(mpc1)*alpha);
%% adjust default measurement noise model gains
mpc1.Model.Noise = mpc1.Model.Noise/alpha;
%% specify simulation options
options = mpcsimopt();
options.UnmeasuredDisturbance = mpc1_UDSignal;
options.OutputNoise = mpc1_ODSignal_1;
options.RefLookAhead = 'off';
options.MDLookAhead = 'off';
options.Constraints = 'on';
options.OpenLoop = 'off';
%% run simulation
sim(mpc1, 101, mpc1_RefSignal_1, [], options);
