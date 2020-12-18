
% x=-2:0.02:4;
% f=(exp(x) - 3*713/(713+100)*x.^2 );
% plot(x,f);grid on
% fsolve(,0.5);
function [y] = a1_12(x)
y = exp(x) - 3*713/(713+100)*x.^2 ;
% y=exp(x) - (1426*x)/271;
end