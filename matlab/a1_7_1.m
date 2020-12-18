function [y] = a1_7_1(x)
y=(2*x.*(x>=0&x<=1/2))+(2*(1-x).*(x>1/2&x<=1));
end
 %fplot(@a1_7_1,[0,1]);grid on
 %这个是调用函数