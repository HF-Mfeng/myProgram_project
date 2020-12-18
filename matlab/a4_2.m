clear;clc
n=0;
for q=1:500
    p=sqrt(1+3*q^2);
    if(p==floor(p))
        n=n+1;
        fprintf('n=%i,p=%i,q=%i,c=%i,d=%i,e=%i\n',n,p,q,p+q,p+2*q,p-q);
    end
end
