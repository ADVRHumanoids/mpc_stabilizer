clear all; clc

%% Generate basic continuous-time model
I = eye(2,2);
Z = zeros(2,2);
h = 0.9;
g = 9.8;
omega = sqrt(g/h);

A = [Z I Z;
    Z Z I;
    Z Z Z];

B_u = [Z;
    Z;
    I];

B_d = B_u *0;

C = [I Z -I/omega^2;
    I Z  Z];


D_u = [Z; Z];
D_d = [I; Z];

B = [B_u B_d];
D = [D_u D_d];


p_ct = ss(A,B_u,C,[]);
p_ct_d = ss(A,B,C,D);

%% Discretize model

Ts = 0.05;

p_dt = c2d(p_ct, Ts);
p_dt_d = c2d(p_ct_d, Ts);


%% Generate extended model with delayed output disturbance
[Adt, Bdt, Cdt, Ddt] = ssdata(p_dt_d);

Adt(8,8) = 0;
Bdt(7:8,3:4) = I;
Cdt(1:2, 7:8) = I;

p_ext = ss(Adt, Bdt, Cdt, [], Ts);



