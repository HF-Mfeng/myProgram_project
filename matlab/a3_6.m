clear;
clc;
A2=[3/4,1/2,1/4;1/8,1/4,1/2;1/8,1/4,1/4];
P0=[0.5;0.25;0.25];
for i = 1:20
	P0(:,i+1)=A2*P0(:,i);
end
P0
