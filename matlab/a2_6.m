
clc;
clear;

% syms times
% times = 0;
% % f=inline('((129)*x+713)/(x^2+(129))');
 f=@(x)((129*x+713)/(x^2+129));
% amf=[];
% h=[];
% for j = 1:50
%     amf(j) = j;
%     x0=j;                %初始值
%     %times = 0 ;
%     for i=1:1000
%         x0=f(x0);
% %         fprintf('%3g,%.60f\n',i,x0);
%         if ( abs( x0 - 713^(1/3) ) == 0 )% < 1e-50 )
%             times = times + 1 ;
%             h(times) = i ;  
%             break ;
%         end
%     end 
% end
% % for j = 1:1000
% %    fprintf('%4g,%3g\n',j,h(j)); 
% % end
% plot(amf,h,'.r');grid on
% %fprintf('    %.60f\n\n',713^(1/3));
 
syms x
h=diff(f(x),x);
b = subs(h,x,(713^(1/3)));
abs(b)-1







% clc;
% clear;
% f=@(x)((129*x+713)/(x^2+129));
% x0=10000;                %初始值
% for i=1:100
%     x0=f(x0);
%      fprintf('%3g,%.50f\n',i,x0);
% end
% fprintf('    %.50f\n\n',713^(1/3));
%plot(amf,h,'.r');grid on


