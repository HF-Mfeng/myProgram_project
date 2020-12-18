s(1)=(sin(1))^715;
for n=2:100
a(n)=(sin(n))^715./n.^2;
s(n)=a(n)+s(n-1);
plot(n-1,s(n-1),'.')
hold on
end