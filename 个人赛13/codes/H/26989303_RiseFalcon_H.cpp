#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353;
const int MAXN=510;
LL n,m,k;
LL a[MAXN][MAXN];
LL row[MAXN],col[MAXN];
int main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			scanf("%lld",&a[i][j]);
			a[i][j]%=mod;
		}
	}
	char str[32];
	for(int i=1;i<=k;++i) {
		LL y,z;
		scanf("%s%lld%lld",str,&y,&z);
		if(str[0]=='r') {
			row[y]=z;
		}else {
			col[y]=z;
		}
	}
	LL ans=0;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			ans+=max(row[i],col[j])%mod*a[i][j]%mod;
			ans%=mod;
		}
	}printf("%lld\n",ans);
	return 0;
}