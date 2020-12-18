A=str2sym('[9,5;2,6]');
[P,D]=eig(A);
Q=inv(P);
syms n;
Xn=P*(D.^n)*Q*[1;2]
