
clear;clc;
syms k pk u v;
A=[3/4,7/18;1/4,11/18];
[P,D]=eig(A);
eqns = [u*P(1,1)+v*P(1,2)-1/2==0,u*P(2,1)+v*P(2,2)-1/2==0];
vars = [u v];
[solu,solv]=solve(eqns,vars);
% u=solve('u*P(1,1)+v*P(1,2)-1/2==0','u*P(2,1)+v*P(2,2)-1/2==0','u','v');
pk = a.u*D(1,1).^k*P(:,1)+a.v*P(2,2)^k*P(:,2)
vpa(limit(pk,k,100),10)
