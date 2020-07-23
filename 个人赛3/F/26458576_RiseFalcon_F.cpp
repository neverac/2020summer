#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=2E5+10;
typedef long long LL;
LL input() {
	LL x;
	scanf("%lld",&x);
	return x;
}
struct suc {
	LL l,r;
	suc(LL a=0,LL b=0) {
		l=a;
		r=b;
	}
}a[MAXN];
bool operator <(const suc&a,const suc&b) {
	return a.l<b.l;
}
LL w[MAXN];
bool check(LL x,LL s,int n) {
	int l=0,r=0,half=n/2;
	LL sum=0;
	for(int i=1;i<=n;++i) {
		if(a[i].r<x) {
			++l;
			w[i]=a[i].l;
			sum+=w[i];
		}
		else if(a[i].l>=x) {
			++r;
			w[i]=a[i].l;
			sum+=w[i];
		}else w[i]=0;
	}
	for(int i=1;i<=n;++i) {
		if(!w[i]) {
			if(l<half) {
				++l;
				w[i]=a[i].l;
				sum+=w[i];
			}else {
				++r;
				w[i]=x;
				sum+=w[i];
			}
		}
	}
	if(l>half)return false;
	else if(sum>s)return false;
	else return true;
}
int doing() {
	LL n=input();
	LL s=input();
	for(int i=1;i<=n;++i) {
		a[i].l=input();
		a[i].r=input();
	}
	sort(a+1,a+n+1);
	LL l=0,r=s,ans=0;
	while(l<=r) {
		LL mid=(l+r)>>1;
		bool temp=check(mid,s,n);
		/*
		printf("(%lld,%lld,%lld):=%d\n",l,r,mid,temp?1:0);
		for(int i=1;i<=n;++i) {
			printf("[%lld,%lld]:=%lld\n",a[i].l,a[i].r,w[i]);
		}*/
		if(temp) {
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}printf("%lld\n",ans);
	return 0;
}
int main() {
	int t=input();
	while(t-->0) {
		doing();
	}return 0;
} 