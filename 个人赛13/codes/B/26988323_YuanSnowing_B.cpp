#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	int n;
	double ans=1000000,x,y,z;
	cin >> n;
	while(n --){
		cin >> x >> y >>z;
		ans = min(ans,sqrt(x*x+y*y+z*z));
	}
	printf("%.3lf",ans);
	return 0;
}

