#include <iostream>
#include <cstdio>


using namespace std;


int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        double x1,x2,x3,y1,y2,y3;
        double xx1,yy1,xx2,yy2,xx3,yy3;

        scanf("%lf%lf%lf%lf%lf%lf",&xx1,&yy1,&xx2,&yy2,&xx3,&yy3);
        x2=0;
        y2=0;
        x1=xx1-xx2;
        y1=yy1-yy2;
        x3=xx3-xx2;
        y3=yy3-yy2;
        double a,b,c;
        b=((x2*x2-x3*x3)*(y1-y2)-(x1*x1-x2*x2)*(y2-y3))/((x2*x2-x3*x3)*(x1-x2)-(x1*x1-x2*x2)*(x2-x3));
        a=(y1-y2-b*(x1-x2))/(x1*x1-x2*x2);
        c=y1-a*x1*x1-b*x1;
        double k,m;
        k=(y3-y2)/(x3-x2);
        m=y3-k*x3;
        double j=x3-x2;
        double ans;
        ans=a*j*j*j/3+(b-k)*j*j/2+(c-m)*j;
        printf("%.2lf\n",ans);
    }

    return 0;
}