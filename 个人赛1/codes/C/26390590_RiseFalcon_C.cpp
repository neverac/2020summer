#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int MAXN=1E5+10;
int q[MAXN],tong[MAXN],a[MAXN];
long long sumans;
int doing() {
	int N;
	scanf("%d",&N);
	memset(tong,0,sizeof(int)*(N+10));
	memset(a,0,sizeof(int)*(N+10));
	memset(q,0,sizeof(int)*(N+10));
	
	for(int i=1;i<=N;++i) {
		tong[i]=1;
	}tong[N+1]=0;
	for(int i=1;i<=N;++i) {
		scanf("%d",&q[i]);
	}
	for(int i=1;i<=N;++i) {
		if(q[i]!=q[i-1]) {
			a[i]=q[i];
			tong[q[i]]=0;
		}
	}
	int mx=0;
	int left=1;
	for(int i=1;i<=N;++i) {
		if(a[i]==0) {
			while(left<=N&&!tong[left])++left;
			a[i]=left;
			tong[left]=0;
		}
		mx=max(mx,a[i]);
		if(mx!=q[i]) {
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=N;++i) {
		printf("%d ",a[i]);
	}printf("\n");
	return 0;
}
int main() {
	int T;scanf("%d",&T);
	while(T-->0)doing();
	return 0;
} 