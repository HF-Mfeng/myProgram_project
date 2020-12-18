function [y] = a1_7_2(x)
y = (1.*(x>=pi/4)) + (atan(x).^3.*(-pi/4<x & x<pi/4)) + (-1.*(x<=-pi/4)) ;
end