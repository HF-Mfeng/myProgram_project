x=-5:0.1:5;y=-10:0.1:10;
[X Y]=meshgrid(x,y);Z=328*X.^2+Y.^4;
mesh(X,Y,Z); 
