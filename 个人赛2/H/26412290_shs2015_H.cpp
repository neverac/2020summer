#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int N,K;
LL  cnt1,cnt2,x,y;
LL lcm = 0;
bool Check(LL n){
	LL ry = max(cnt2 - (n / x - n / lcm),0LL);
	LL rx = max(cnt1 - (n / y - n / lcm),0LL);
	return n + n/lcm - n/x - n/y >= rx + ry;
}
int main(){
	scanf("%lld%lld%lld%lld",&cnt1,&cnt2,&x,&y);
	lcm = x * y;
	LL l = 1,r = (cnt1 + cnt2) * 100,mid,ans;
	loop:
		mid = (l + r)/2;
		//printf("l = %d,r = %d\n",l,r);
		if(Check(mid))ans = mid,r = mid-1;
		else l = mid+1;
	if(l <= r)goto loop;
	printf("%lld\n",ans);
	return 0;
}
/*
3 1 2 3
*/