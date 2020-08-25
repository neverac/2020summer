#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	double Min=0x3f3f3f3f,x,y,z;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%lf%lf%lf",&x,&y,&z);
		Min=min(Min,sqrt(x*x+y*y+z*z));
	}
	printf("%.3lf\n",Min);
return 0;
}