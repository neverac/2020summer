#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
LL tong[MAXN];
int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b) {
	return a*b/gcd(a,b);
}
int doing(int T) {
	LL n,a,b,cnt=0;
	scanf("%lld%lld%lld",&n,&a,&b);
	LL c=gcd(a,b);
	cnt=n/c;
	printf("Case #%d: ",T);
	if(cnt%2==0) {
		printf("Iaka\n");
	}else printf("Yuwgna\n");
	return 0;
}
int main() {
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i) {
		doing(i);
	}
	return 0;
} 