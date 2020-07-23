#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=600+10;
typedef long long LL;
const LL mod=998244353;
const int INF=~0U>>3;
char w[MAXN];
LL input() {
	LL x;
	scanf("%lld",&x);
	return x;
}

int main() {
	int n=input();
	scanf("%s",w);
	int st=0,mw=INF;
	for(int i=0;w[i];++i) {
		if(w[i]=='-') {
			st--;
			mw=min(mw,st);
		}else {
			st++;
			mw=min(mw,st);
		}
	}
	if(mw>=0) {
		printf("%d\n",st);
	}else {
		printf("%d\n",st-mw);
	}
	return 0;
} 