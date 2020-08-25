#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;


double x,y,z;

double get_dis(double x,double y,double z)
{
	return sqrt(x*x+y*y+z*z);
}


int T;
int main()
{
	double ans = 1e15+100;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&x,&y,&z);
        ans = min(ans,get_dis(x,y,z));
    }
    printf("%.3lf\n", ans);
	return 0;
}
