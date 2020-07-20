#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1E6+10;
int a[MAXN];
struct range {
	int bg,ed,step;
	range(int a,int b,int c) {
		bg=a;ed=b;step=c;
	}
	int next() {
		bg+=step;
	}
	int end() {
		return bg>ed;
	}
	int now() {
		return bg;
	}
};
int getAns(int n,int k) {
	range left(1,n,1),right(n,1,-1);
	range pw[2]={left,right};
	int pt=0;
	for(int i=1;i<=k;++i) {
		printf("%d ",pw[pt].now());
		pw[pt].next();
		pt^=1;
	}
	pt^=1;
	for(int i=k+1;i<=n;++i) {
		printf("%d ",pw[pt].now());
		pw[pt].next();
	}
	return 0;
} 
int main() {
	int n;int k;scanf("%d%d",&n,&k);
	getAns(n,k);
	return 0;
} 