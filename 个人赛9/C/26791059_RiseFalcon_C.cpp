#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const LL INF=~0ULL>>2;
const int MAXN=1E6+10;
struct point {
	LL id[3];
	point(){
		memset(id,0,sizeof id);
	}
	point(int x,int y,int z) {
		id[0]=x;
		id[1]=y;
		id[2]=z;		
	}
};
LL pw2(const LL&x) {
	return x*x;
}
LL dist(const point&a,const point&b) {
	LL ans=0;
	for(int i=0;i<3;++i) {
		ans+=pw2(a.id[i]-b.id[i]);
	}return ans;
}
point a[MAXN];
bool vis[MAXN];
int main() {
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		for(int j=0;j<3;++j) {
			scanf("%lld",&a[i].id[j]);
		}
	}
	for(int i=1;i<=n;++i) {
		if(vis[i])continue;
		LL ans=INF,idx=0;
		for(int j=i+1;j<=n;++j) {
			if(vis[j])continue;
			if(dist(a[i],a[j])<ans) {
				idx=j;
				ans=dist(a[i],a[j]);
			}
		}
		vis[i]=1;
		vis[idx]=1;
		printf("%d %d\n",i,idx);
		/*
		for(int k=i+1;k<=n;++k) {
			if(vis[k])continue;
			bool flag=true;
			for(int v=0;v<3;++v) {
				LL min_id=min(a[i].id[v],a[idx].id[v]);
				LL max_id=min(a[i].id[v],a[idx].id[v]);
				if(min_id<=a[k].id[v]&&a[k].id[v]<=max_id) {
					flag=true;
				}else {flag=false;break;}
			}
			if(flag)printf("????\n");
		}*/
	}
	return 0;
} 