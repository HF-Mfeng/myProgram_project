% % f=inline('2*x.*(0<=x<=0.5) + 2*(1-x).*(0.5<x<=1)');
% % syms f n
% f=inline('1-2*abs(x-1/2)');
% 
% x=[];
% y=[];
% x(1)=0.5;
% y(1)=0;
% x(2)=x(1);
% y(2)=f(x(2));
% for i=1:10
%     x(2*i+1)=y(2*i);
%     x(2*i+2)=x(2*i+1);
%     y(2*i+1)=x(2*i+1);
%     y(2*i+2)=f(x(2*i+2));
% end
% plot(x,y,'r');grid on;hold on;
% ezplot(f,[0,1]);
% hold on;
% % plot(x,[0,1]);

clc;
syms g
g = inline('1-2*abs(x-1/2)');
x=[];
y=[];
x(1)=0.005;
y(1)=0;
x(2)=x(1);
y(2)=g(x(2));
for i=1:100
    x(2*i+1)=y(2*i);
    x(2*i+2)=x(2*i+1);
    y(2*i+1)=x(2*i+1);
    y(2*i+2)=g(x(2*i+2));
end
plot(x,y,'r');grid on;hold on;
ezplot(g,[0,1]);
hold on;
ezplot('x',[0,1]);

