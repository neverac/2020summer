#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
const int MAXN=60;
const int ud[]={0,-1,0,1};
const int lr[]={-1,0,1,0};
int w[MAXN][MAXN],vis[MAXN][MAXN];
bool judge(ll cnt1,ll cnt2,ll x,ll y,ll N) {
	return std::max(0ll,cnt1-N/y+N/(x*y))+std::max(0ll,cnt2-N/x+N/(x*y))<=N-N/x-N/y+N/(x*y);
}
int doing() {
	ll cnt1,cnt2,x,y;
	scanf("%lld%lld%lld%lld",&cnt1,&cnt2,&x,&y);
	ll l=cnt1+cnt2,r=1E14,ans=-1;
	while(l<=r) {
		ll mid=(l+r)>>1;
		if(judge(cnt1,cnt2,x,y,mid)) {
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
int main() {
	doing();
	return 0;
} 