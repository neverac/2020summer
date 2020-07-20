#include <bits/stdc++.h>
using namespace std;
double a,x[4],y[4],e,f,b,c,ans;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<3;i++)scanf("%lf%lf",&x[i],&y[i]);
		a=(y[1]-y[0])/pow(x[1]-x[0],2);
		b=-2*a*x[0];
		c=a*x[0]*x[0]+y[0];
		e=(y[2]-y[1])/(x[2]-x[1]);
		f=y[2]-e*x[2];
		ans=a/3*(pow(x[2],3)-pow(x[1],3))+(b-e)/2*(pow(x[2],2)-pow(x[1],2))+(c-f)*(x[2]-x[1]);
		printf("%.2lf\n",ans);
	}
	return 0;
}