#include <bits/stdc++.h>
using namespace std;
long long n,m,gc,tot;
typedef long long ll;
int const maxn=1e5+7;
ll a[maxn<<1];
int main(){
	scanf("%lld",&n);
	n<<=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	n>>=1;
	ll x=a[n]-a[1],y=a[2*n]-a[n+1],ans;
	ans=x*y;
	y=a[2*n]-a[1];
	for(int i=2;i<=n;i++){
		x=a[i+n-1]-a[i];
		ans=min(ans,x*y);
	}

	printf("%lld\n",ans);
	return 0;
}