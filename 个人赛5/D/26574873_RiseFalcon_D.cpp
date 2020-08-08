#include <cstdio>
typedef long long LL;
int main() {
	LL T;scanf("%lld",&T);
	while(T-->0) {
		LL n,k;
		scanf("%lld%lld",&n,&k);
		if(k%(n-1)==0)printf("%lld\n",k/(n-1)*n+k%(n-1)-1);
		else printf("%lld\n",k/(n-1)*n+k%(n-1));
	}
	return 0;
}