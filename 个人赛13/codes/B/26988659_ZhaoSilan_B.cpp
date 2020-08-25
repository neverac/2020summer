//交错了账号qaq
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    double t=100000000;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        t=min(t,sqrt(1.0*(x*x+y*y+z*z)));
    }
    printf("%.3lf\n",t);
    return 0;
}