#include <bits/stdc++.h>
using namespace std;
struct node {
	double x,y;
}a[3];
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>a[0].x>>a[0].y;
		cin>>a[1].x>>a[1].y;
		cin>>a[2].x>>a[2].y;
		double an=(a[1].y-a[0].y)/((a[1].x-a[0].x)*(a[1].x-a[0].x));
		double bn=-2.0*an*a[0].x;
		double cn=an*a[0].x*a[0].x+a[0].y;
		double k=(a[1].y-a[2].y)/(a[1].x-a[2].x);
		double b=a[2].y-(a[2].x*k);
		double ans=1.0/3*an*(a[1].x*a[1].x*a[1].x-a[2].x*a[2].x*a[2].x)+(1.0/2*bn-1.0/2*k)*(a[1].x*a[1].x-a[2].x*a[2].x)+(cn-b)*(a[1].x-a[2].x);
		printf("%.2lf\n",abs(ans));
	}

	return 0;
}

