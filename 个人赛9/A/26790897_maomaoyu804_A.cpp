#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[200005];

int main(){
	ll n;scanf("%lld",&n);
	for(ll i=1;i<=n*2;i++) scanf("%lld",&num[i]);
	sort(num+1,num+n*2+1);
	ll ans=num[2*n]*num[2*n];
	for(ll i=2;i<=n;i++){
		ans=min(ans,(num[i+n-1]-num[i])*(num[n*2]-num[1]));
	}
	ans=min(ans,(num[n]-num[1])*(num[n*2]-num[n+1]));
	cout<<ans<<endl;
	return 0;
}