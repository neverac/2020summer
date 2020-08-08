#include <cstdio> 
#include <algorithm>
using namespace std;
const int MAXN=2E5+10;
int a[MAXN],f[MAXN],g[MAXN];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
	}
	f[0]=0;
	for(int i=1;i<=n;++i) {
		if(a[i]>a[i-1]) {
			f[i]=f[i-1]+1;
		}else {
			f[i]=1;
		}
	}
	g[n+1]=0;
	for(int i=n;i>=1;--i) {
		if(a[i]<a[i+1]) {
			g[i]=g[i+1]+1;
		}else {
			g[i]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) {
		if(a[i-1]<a[i+1]) {
			ans=max(ans,f[i-1]+g[i+1]);
		}
		ans=max(ans,f[i]);
		ans=max(ans,g[i]);
	}printf("%d\n",ans);
	return 0;
} 