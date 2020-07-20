#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double x1,x2,x3,y1,y2,y3;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double a=(y2-y1)/((x2-x1)*(x2-x1));
        
        double k=(y3-y2)/(x3-x2);
        double b=y2-k*x2;
        double xx=x2;
        double ans=1.0/3.0*a*xx*xx*xx-0.5*(k+2*a*x1)*xx*xx+(a*x1*x1+y1-b)*xx;
        xx=x3;
         double ans1=1.0/3.0*a*xx*xx*xx-0.5*(k+2*a*x1)*xx*xx+(a*x1*x1+y1-b)*xx;
        
        
        if(ans<ans1)
            printf("%.2lf\n",ans1-ans);
        else
            printf("%.2lf\n",ans-ans1);
    }
    return 0;
}