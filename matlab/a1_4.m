clc;
syms y x 
y = (713/1000+x)^(1/3);
taylor(y,x,0,'Order',5)