% f=inline('3.4*x*(1-x)');
% x=[];y=[];x(1)=0.5;y(1)=0;x(2)=x(1);y(2)=f(x(1));
% for i = 1:1000
% 	x(1+2*i)=y(2*i);
% 	x(2+2*i)=x(1+2*i);
% 	y(1+2*i)=x(1+2*i);
% 	y(2+2*i)=f(x(2+2*i));
% end
% hold on;
% grid on;
% plot(x,y,'r');
% ezplot('x',[0,1]);
% ezplot(f,[0,1]);
clear;clc;
y = inline('u*x*(1-x)');
% y=@(a,x)(a*x*(1-x));
x0=0.5;r=0;p=[];
syms i 
i = 0;
for a=2.8:0.01:3.84
   for i=1:300
      x0 = y(a,x0);
      if i > 100
          r=r+1;
          p(:,r) = [a,x0];  
      end
   end
end
plot(p(1,:),p(2,:),'.')
axis([2.8,3.84,0,1]);
% axis([0,1,3,4]);
