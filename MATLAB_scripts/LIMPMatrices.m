clear all; clc

I = eye(2,2);

A = [0*I I 0*I;
     0*I 0*I I;
     0*I 0*I 0*I];
 
 B_u = [0*I;
      0*I;
      I];

 B_d = B_u *0;
 
 C = [I 0*I -I;
     I 0*I 0*I;
     0*I I 0*I];
 
 
 D_u = [0*I; 0*I; 0*I];
 D_d = [I; 0*I; 0*I];
 
 B = [B_u B_d];
 D = [D_u D_d];
 
 
 p_ct = ss(A,B_u,C,[]);
 p_ct_d = ss(A,B,C,D);
 
 Ts = 0.2;
 
 p_dt = c2d(p_ct, Ts);
 p_dt_d = c2d(p_ct_d, Ts);