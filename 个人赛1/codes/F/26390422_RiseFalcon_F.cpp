#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int MAXN=1E5+10;
int f[MAXN],sum[MAXN],tong[MAXN],a[MAXN];
long long sumans;

int main() {
	int N,K;
	scanf("%d",&N);
	sumans=0;
	for(int i=1;i<=N;++i) {
		scanf("%d",&a[i]);
		sumans+=a[i];
		tong[a[i]]+=1;
	}
	scanf("%d",&K);
	for(int i=1;i<=K;++i) {
		int b,c;scanf("%d%d",&b,&c);
		sumans-=1ll*tong[b]*b;
		sumans+=1ll*tong[b]*c;
		
		tong[c]+=tong[b];
		tong[b]=0;
		
		printf("%lld\n",sumans);
	}
	
	return 0;
} 