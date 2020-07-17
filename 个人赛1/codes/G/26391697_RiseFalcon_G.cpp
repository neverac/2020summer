#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int MAXN=1E5+10;
int t[MAXN],g[MAXN],b[MAXN];
long long sumans;
int main() {
	int N,M;
	int mx=0;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i) {
		scanf("%d",&b[i]);
		sumans+=1ll*M*b[i];
		mx=max(mx,b[i]);
	}
	sort(b+1,b+N+1);
	reverse(b+1,b+N+1);
	for(int i=1;i<=M;++i) {
		scanf("%d",&g[i]);
	}
	sort(g+1,g+M+1);
	//reverse(g+1,g+M+1);
	int left=1;
	for(int i=1;i<=M;++i) {
	//	printf("%d %d\n",g[i],b[left]);
		while(left<=N&&t[left]==M-1)++left;
		if(g[i]<mx||left>N) {
			sumans=-1;
			break; 
		}
		sumans+=g[i]-b[left];
		if(g[i]!=b[left])t[left]++;
	}
	printf("%lld\n",sumans);
	return 0;
} 