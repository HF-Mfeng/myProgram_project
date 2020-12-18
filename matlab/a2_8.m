syms x y g
y=(pi-x)*cos(i*x);
g=(pi-x)*sin(i*x);
a=[];
b=[];
n=[];
for i = 1:300
	n(i)=i;
	a(i)=2/pi*int(y,x,0,pi);
	b(i)=2/pi*int(g,x,0,pi);
end
plot(n,a,'r');
grid on