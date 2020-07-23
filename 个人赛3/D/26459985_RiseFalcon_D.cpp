#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1E6+10;
typedef long long LL;
const LL mod=998244353;
const int INF=~0U>>3;
int w[MAXN];
LL input() {
	LL x;
	scanf("%lld",&x);
	return x;
}

int main() {
	int n=input();
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;++i) {
		int x=input();
		if(x==1)++cnt1;
		else ++cnt2;
	}
	int tail=0;
	if(cnt2) {
		--cnt2;
		w[tail++]=2;
	}
	if(cnt1) {
		--cnt1;
		w[tail++]=1;
	}
	while(cnt2) {
		--cnt2;
		w[tail++]=2;
	}
	while(cnt1) {
		--cnt1;
		w[tail++]=1;
	}
	for(int i=0;i<n;++i) {
		printf("%d ",w[i]);
	}printf("\n");
	return 0;
} 