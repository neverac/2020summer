#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
typedef long long LL;
const LL INF=~0ULL>>2;
const int MAXN=1023;
char s[MAXN];
int doing() {
	LL A,B,C,S;
	if(scanf("%lld%lld%lld%lld",&A,&B,&C,&S)!=4)
		return 0;
	LL one=(1<<16)-1;
	LL zero=(1<<16)-1;
	for(int i=0;i<16;++i) {
		s[i]=-1; 
	} 
	for(int i=0;i<C;++i) {
		one=S&one;
		zero=(~S)&zero;
		S=(A*S+B)%C;
	}
	for(int i=15;i>=0;--i) {
		int u=one&(1<<i);
		int d=zero&(1<<i);
		if(u) {
			printf("1");
		}else if(d) {
			printf("0");
		}else printf("?");
	}printf("\n");
	return 1;
}
int main() {
	while(doing()) {
		; 
	} 
	return 0;
} 