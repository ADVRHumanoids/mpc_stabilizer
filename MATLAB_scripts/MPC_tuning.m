%% create MPC controller object with sample time
mpc1 = mpc(p_ct, 0.2);
%% specify prediction horizon
mpc1.PredictionHorizon = 20;
%% specify control horizon
mpc1.ControlHorizon = 2;
%% specify nominal values for inputs and outputs
mpc1.Model.Nominal.U = [0;0];
mpc1.Model.Nominal.Y = [0;0];
% NUM = cell(4);
% NUM(:,:) = {0};
% NUM{1,1} = sqrt(1000);
% NUM{2,2} = sqrt(1000);
% NUM{3,3} = sqrt(1);
% NUM{4,4} = sqrt(1);
% DEN = cell(4);
% DEN(:,:) = {1};
% DEN{1,1} = [1 0];
% DEN{2,2} = [1 0];
% DEN{3,3} = 1;
% DEN{4,4} = 1;
% 
% mpc1.Model.Noise = tf(NUM, DEN);
%% specify constraints for OV
mpc1.OV(1).Min = -1;
mpc1.OV(1).Max = 1;
mpc1.OV(2).Min = -1;
mpc1.OV(2).Max = 1;
%% specify overall adjustment factor applied to weights
beta = 1.0408;
%% specify weights
mpc1.Weights.MV = [0 0]*beta;
mpc1.Weights.MVRate = [0.1 0.1]/beta;
mpc1.Weights.OV = [1 1 0 0 0 0]*beta;
mpc1.Weights.ECR = 100000;
%% specify simulation options
Nsim = 100;
Tref = 10;
Tnoise = 50;
options = mpcsimopt();
mpc1_ODSignal = zeros(Nsim, 6);
mpc1_ODSignal(Tnoise:end, 1) = 1;
options.OutputNoise = mpc1_ODSignal;
options.RefLookAhead = 'off';
options.MDLookAhead = 'off';
options.Constraints = 'on';
options.OpenLoop = 'off';
%% run simulation

mpc1_RefSignal = zeros(Nsim, 6);
mpc1_RefSignal(Tref:end, 1:2) = 1;
% sim(mpc1, Nsim, mpc1_RefSignal, [], options);

%% Simulate MPC with |mpcmove|
% First, obtain the discrete-time state-space matrices of the plant.
x = [0 0 0 0 0 0]';           % Initial state of the plant
xmpc = mpcstate(mpc1);    % Initial state of the MPC controller
r = [1 1 1 1 0 0]';                      % Output reference signal
Tstop = 30;

%%
% Store the closed-loop MPC trajectories in arrays |YY|, |UU|, and |XX|.
YY=[];
UU=[];
XX=[];

%%
% Run the simulation loop
for t=0:round(Tstop/Ts)-1
    % Store states
    XX = [XX,x]; %#ok<*AGROW>
    % Define measured disturbance signal
    v = [0 0 0 0 0 0]';
    if t*Ts>=5
        v = [1 0 0 0 0 0]';
    end

    % Plant equations: output update (no feedthrough from MV to Y)
    y = C*x + v;
    YY = [YY,y];
    % Compute MPC action
    u = mpcmove(mpc1,xmpc,y,r);
    % Plant equations: state update
    x = p_dt.A*x + p_dt.B*u;
    UU = [UU,u];
end

