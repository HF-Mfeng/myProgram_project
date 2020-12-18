
clc;clear;
f = @(x) (1000*x + 713)/(x^2 + 1000);
figure
hold on
for init = 1:100
    y = f(init);
    count = 0;
    while abs(y - 721^(1/3)) >= 1e-5
        count = count + 1;
        y = f(y);
    end
    scatter(init,count,'b.');
end
box on
hold off
xlabel(['初始值']);
ylabel(['迭代次数']);

