clc;
f=inline('(x+713/x)/2');
x0=3;%这里需要更改
for i=1:20
   x0=f(x0);
   fprintf('%i,%.8f\n',i,x0);
end
fprintf('\n\n\n');
x0=-3;%这里需要更改
for i=1:20
   x0=f(x0);
   fprintf('%i,%.8f\n',i,x0);
end