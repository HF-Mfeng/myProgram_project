%syms x y
%y = exp(a*x^2)*
function [y] = aa(a,b,x)
y=exp(a*x^2)*cos(b*x);	
end