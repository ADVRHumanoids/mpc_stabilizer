%% Discretize model

Ts = 0.001;

p_dt = c2d(p_ct, Ts);
p_dt_d = c2d(p_ct_d, Ts);


%% Generate extended model with delayed output disturbance
[Adt, Bdt, Cdt, Ddt] = ssdata(p_dt_d);

Adt(8,8) = 0;
Bdt(7:8,3:4) = I;
Cdt(1:2, 7:8) = I;

p_ext = ss(Adt, Bdt, Cdt, [], Ts);