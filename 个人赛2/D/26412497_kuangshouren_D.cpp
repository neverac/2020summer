#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
double x[4],y[4];
int T,nnn;
int main()
{
	cin>>T;
	for(int i=1;i<=T;++i)
	{
	cin>>x[1]>>y[1];
	cin>>x[2]>>y[2];
	cin>>x[3]>>y[3];
	double a=abs((x[1]-x[2])*(y[1]-y[2])*(double)(2)/3);
	double b=abs((x[1]-x[3])*(y[1]-y[3])*(double)(2)/3);
	double z=y[2]+(y[3]-y[2])/(x[3]-x[2])*(x[1]-x[2]);
	double c=abs((x[1]-x[2])*(z-y[2]))/2;
	double d=abs((x[1]-x[3])*(z-y[3]))/2;
	if(c<d)swap(c,d);
	printf("%0.2lf\n",a+b-c+d);
	}
	return 0;
}