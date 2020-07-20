#include <stdio.h>
using namespace std;

int main()
{
	double x[5],y[5],a,b,c,d,e,ans;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=3;++i)
			scanf("%lf%lf",&x[i],&y[i]);
		a=(y[2]-y[1])/((x[2]-x[1])*(x[2]-x[1]));
		b=-2*a*x[1];
		c=a*x[1]*x[1]+y[1];
		d=(y[2]-y[3])/(x[2]-x[3]);
		e=y[2]-d*x[2];
		
		ans=(a/3*x[3]*x[3]*x[3]+b/2*x[3]*x[3]+c*x[3]-d/2*x[3]*x[3]-e*x[3])-(a/3*x[2]*x[2]*x[2]+b/2*x[2]*x[2]+c*x[2]-d/2*x[2]*x[2]-e*x[2]);
		
		printf("%.2lf\n",ans);
	}
return 0;
}