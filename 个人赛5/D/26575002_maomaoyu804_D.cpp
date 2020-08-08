#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t;scanf("%lld",&t);
	while(t--){
		ll n,k;scanf("%lld%lld",&n,&k);
		n--;
		ll ans=k/n*(n+1);
		if(k%n==0) ans--;
		ans+=(k%n);
		printf("%lld\n",ans);
	}
	return 0;
}