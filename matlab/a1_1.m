% clear;clc;
syms x y
y = exp(x)*cos(713*x/1000);
diff(y,x,2)
g=diff(y,x,6);
subs(g,x,0)
