#include<cstdio>
#include<queue>
#include <cstring>
const int ud[4]={0,1,0,-1};
const int lr[4]={1,0,-1,0};
const int MAXN=1E6+10;
struct node {
	int x,y;
	node(int a=0,int b=0) {
		x=a;y=b;
	}
};
long long a[MAXN];
long long gcd(long long a,long long b) {
	return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b) {
	return a*b/gcd(a,b);
}
int main() {
	long long N,M;
	scanf("%lld%lld",&N,&M);
	for(int i=0;i<M;++i) {
		scanf("%lld",&a[i]);
	} 
	long long ans=0;
	for(int s=1;s<(1<<M);++s) {
		long long mul=1,cnt=0;
		for(int i=0;i<M;++i) {
			if(s&(1<<i)) {
				mul=lcm(mul,a[i]);
			//mul=mul*a[i];
				++cnt;
				if(mul>N)break;
			}
		}
		if(mul>N)continue;
		if(cnt%2==1) {
			ans+=N/mul;
		}else {
			ans-=N/mul;
		}
	//	printf("s:%lld mul:%lld delta:%lld\n",s,mul,N/mul);
	}
	printf("%lld\n",ans);
	return 0;
} 