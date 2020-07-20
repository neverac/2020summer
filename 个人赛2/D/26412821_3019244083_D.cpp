#include <cstdio>
#include <cmath>
using namespace std;
double x1,x2,y2,x3,y3,k;
double y11;
double func(double x)
{
    return k * pow(x-x1,3)/3 + x*y11;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y11,&x2,&y2,&x3,&y3);
        k=(y2-y11) / pow(x2-x1,2);
        printf("%.2lf\n",func(x3) - func(x2) - (y3+y2)*(x3-x2)/2);
    }
    return 0;
}