#include <cstdio>
typedef long long LL;
LL phi(LL x) {
	LL ans=x; 
	for(LL i=2;i*i<=x;++i) {
		if(x%i==0) {
			ans=ans/i*(i-1);
			while(x%i==0) {
				x/=i;
			}
		}
	} if(x!=1)ans=ans/x*(x-1);
	return ans;
}
LL pow(LL a,LL b,LL mod) {
	LL ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}return ans;
}
LL exponial(LL n,LL m) {
	if(n==0&&m==0)return 1;
	if(n==0||m==1)return 0;
	return pow(n,exponial(n-1,phi(m))+phi(m),m);
}
int main() {
//	for(int i=1;i<=10;++i) {
//		printf("%d ",phi(i));
//	} printf("\n");
	LL n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",exponial(n,m));
	return 0;
}