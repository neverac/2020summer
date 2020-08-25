#include <bits/stdc++.h>
using namespace std;
int main()
{
	double ans = 1000000000;
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i){
		int x,y,z;
		cin>>x>>y>>z;
		ans = min(ans, sqrt(x*x + y*y + z*z));
	}
	printf("%.3lf\n",ans);
	return 0;
}