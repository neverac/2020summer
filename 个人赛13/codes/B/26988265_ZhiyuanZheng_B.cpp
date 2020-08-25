#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	int n;
	cin>>n;
	double best=1e9;
	for (int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		double ans=sqrt(1.0*x*x+1.0*y*y+1.0*z*z);
		best=min(ans,best);
	}
	printf("%.3lf\n",best);
	return 0;
}

