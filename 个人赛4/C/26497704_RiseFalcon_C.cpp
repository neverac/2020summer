#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1E6+10;
LL a[MAXN],dx[MAXN];
int doing() {
	LL n,x;scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;++i) {
		scanf("%1lld",&a[i]);
	}
	dx[0]=0;
	for(int i=1;i<=n;++i) {
		int dx2=(a[i]==0 ? 1:-1);
		dx[i]=dx[i-1]+dx2;
	}
	LL sumdx=dx[n];
	LL ans=0;
	if(x==0)++ans;
	for(int i=1;i<=n;++i) {
		if(sumdx==0&&dx[i]==x) {
			ans=-1;
			break;
		}else if(sumdx!=0) {
			LL v=x-dx[i];
			if(((v>=0&&sumdx>=0)||(v<=0&&sumdx<=0))&&(v%sumdx==0)&&(v/sumdx>=0)) {
				ans+=1;
			}
		}
	}printf("%lld\n",ans);
	return 0;
}
int main() {
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i) {
		doing();
	}
	return 0;
} 