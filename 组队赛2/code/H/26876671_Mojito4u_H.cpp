#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
long long  n,m;
int main(){
	int t;

	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		m=n*(n+1);
		printf("%lld\n",m^(n+1));
	}
	
	return 0;
}