clear;clc
num = 1000 ;
f=@(x)(sin(713/1000*x).^2);
c = linspace(0,pi,num);
x0 = c+pi/(2*num);
y100 = f(x0);
ave = mean(y100)

syms x
eq=sin(713/1000*x).^2==0.0685;
s=solve(eq,x);
s
