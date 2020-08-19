#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
LL a[MAXN*2];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i) {
		scanf("%lld",&a[i]);
	}sort(a+1,a+2*n+1);
	LL ans=(a[n]-a[1])*(a[2*n]-a[n+1]);
	for(int i=2;i+n-1<=2*n-1;++i) {
		ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	//	ans=min(ans,(a[2*n]-a[i])*(a[i+n-1]-a[1]));
	}
	printf("%lld\n",ans);
	return 0;
} 