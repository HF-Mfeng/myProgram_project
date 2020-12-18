
%这部分不用改
clear;clc;
s=[];
n=[];




%下面一部分是第一题
s(1)=0;
n(1)=1;
for i = 2:500
	n(i)=i;
	s(i)=s(i-1)+sin(n(i))^713/n(i)^2;
end
plot(n,s,'.r');
grid on;


%下面一部分是第二题
% s(1)=0;
% n(1)=1;
% s(2)=0;
% n(2)=2;
% s(3)=0;
% n(3)=3;
% for i = 4:500
% 	n(i)=i;
% 	s(i)=s(i-1)+1/log(n(i))^(713/1000);
% end
% plot(n,s,'.b');
% grid on;
