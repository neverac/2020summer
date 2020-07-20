#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
typedef long long ll;
const ll INF=~0ULL>>2;
const int MAXN=60;
const int ud[]={0,-1,0,1};
const int lr[]={-1,0,1,0};
int w[MAXN][MAXN],vis[MAXN][MAXN];
ll trans(char*s,int bg,int ed) {
	long long ans=0;
	for(int i=bg;i<ed;++i) {
		ans=ans*10+s[i]-'0';
	} return ans;
}  
char s[MAXN];
int doing(int T) {
	scanf("%s",s);
	int len=strlen(s);
	ll ans=-INF;
	for(int i=1;i<=3;++i) {
		if(1+1+1+i+1>len)continue;
		ll k=len-1-1-1-i;
		ll a=trans(s,0,k);
		ll b=trans(s,k,k+1);
		ll c=trans(s,k+1,k+2);
		ll d=trans(s,k+2,k+3);
		ll e=trans(s,k+3,k+3+i);
		ans=std::max(a+b-c*d/e,ans);
	}
	for(int i=1;i<=3;++i) {
		if(1+1+1+i+1>len)continue;
		ll k=len-1-1-1-i;
		ll a=trans(s,0,1);
		ll b=trans(s,1,1+k);
		ll c=trans(s,k+1,k+2);
		ll d=trans(s,k+2,k+3);
		ll e=trans(s,k+3,k+3+i);
		ans=std::max(a+b-c*d/e,ans);
	}
	printf("Case #%d: %lld\n",T,ans);
	return 0;
}
int main() {
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i) {
		doing(i);
	}
	return 0;
} 