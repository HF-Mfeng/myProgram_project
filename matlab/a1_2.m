clc;
syms x y 
y = exp(x)*cos(713*x/1000);
diff(y,x,2)
f = diff(y,x,6);
subs(f,x,0)