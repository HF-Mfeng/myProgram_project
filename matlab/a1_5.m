clc;
syms x
x=randi([1,713],1,2);
for n = 3:10
    x(n)=x(n-2)+x(n-1);
end
x