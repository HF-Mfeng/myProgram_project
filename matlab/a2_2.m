clc;
% f = inline('(x-1)/(x+713)');
g = inline('(x+713^2)/(x+713)');
m=inline('x');
% x0=2;
% for i=1:20
%    x0=f(x0); 
%    fprintf('%g,%g\n',i,x0);
% end
% ’¡≤”⁄-0.0014045

x=[];
y=[];
x(1)=200;
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
ezplot(g,[0,1000]);
hold on;
ezplot(m,[0,1000]);

