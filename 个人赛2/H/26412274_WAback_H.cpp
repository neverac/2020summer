#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
ll cnt1,cnt2,x,y,lcm;

bool check(ll n){
	ll c2=cnt2-(n/x-n/lcm);
	ll c1=cnt1-(n/y-n/lcm);
	c2=max(c2,0ll);c1=max(c1,0ll);
	if((n+n/lcm-n/x-n/y)>=c1+c2) return 1;
	return 0;
}

int main(){
	
	scanf("%lld%lld%lld%lld",&cnt1,&cnt2,&x,&y);
	lcm=x*y;
	ll l=1,r=1e18,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}