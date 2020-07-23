#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1E6+10;
typedef long long LL;
const LL mod=998244353;
const int INF=~0U>>3;
LL f[MAXN][2],ms[MAXN][2],h[MAXN][2];
LL input() {
	LL x;
	scanf("%lld",&x);
	return x;
}

int main() {
	int n=input();
	for(int i=1;i<=n;++i) {
		h[i][0]=input();
	}
	for(int i=1;i<=n;++i) {
		h[i][1]=input();
	}
	for(int i=1;i<=n;++i) {
		f[i][0]=h[i][0]+ms[i-1][1];
		f[i][1]=h[i][1]+ms[i-1][0];
		
		ms[i][0]=max(ms[i-1][0],f[i][0]);
		ms[i][1]=max(ms[i-1][1],f[i][1]);
	}
	printf("%lld\n",max(ms[n][0],ms[n][1]));
	return 0;
} 