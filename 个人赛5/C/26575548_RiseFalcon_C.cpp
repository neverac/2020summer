#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL INF=~0ULL>>2;
const LL MAXN=365;
const LL  MAXP=100000;
LL f[2][MAXP+10],gu[MAXN+10];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",&gu[i]);
	}
	
	for(int i=0;i<=MAXP;++i) {
		f[0][i]=-INF;
		f[1][i]=-INF;
	}
	int now=0;
	f[0][0]=100;
	for(int i=0;i<N;++i) {
		for(int j=0;j<=MAXP;++j) {
			f[now^1][j]=-INF;
		}
		for(int j=0;j<=MAXP;++j) {
			if(f[now][j]==-INF)continue; 
			LL guc=min(MAXP-j,f[now][j]/gu[i+1]);
			f[now^1][j+guc]=max(f[now^1][j+guc],f[now][j]-gu[i+1]*guc);
			f[now^1][0]=max(f[now^1][0],f[now][j]+j*gu[i+1]);
			f[now^1][j]=max(f[now^1][j],f[now][j]);
		}
		now^=1;
	}
	/*
	for(int i=0;i<=10;++i) {
		printf("%lld\n",f[now][i]);
	} */ 
	printf("%lld\n",f[now][0]);
	return 0;
}