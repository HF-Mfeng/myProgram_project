% A=str2sym('[0.9,0.5;0.2,0.6]');
% A=str2sym('1/10*[9,5;2,6]');
B=str2sym('[9,5;2,6]');
A=1/10.*B;
% A=[0.9,0.5;0.2,0.6];
[P,D]=eig(A);
Q=inv(P);
syms n;
Xn=P*(D.^n)*Q*[1;2]
format rat
