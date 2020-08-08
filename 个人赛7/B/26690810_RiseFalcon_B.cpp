#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1E5+10;
vector<int>go[MAXN],re[MAXN];
int a[MAXN],cnw,lock;
int vis[MAXN],andrs[MAXN],central[MAXN];
bool dfs(int now,const vector<int>* iv) {
	vis[now]=lock;
	++cnw;
	for(int i=iv[now].size()-1;i>=0;--i) {
		int to=iv[now][i];
		if(vis[to]==lock)continue;
		if(central[to]==1) return true;
		if(dfs(to,iv)) {
			central[now]=1;
			return true;
		}
	}return false;
}
int main() {
	int N,M,sqr;
	const int IVD=30;
	scanf("%d%d",&N,&M);sqr=(N<IVD?N:IVD);
	if(M==0) {
		printf("0");
		return 0;
	}
	for(int i=1;i<=M;++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		go[x].push_back(y);
		re[y].push_back(x);
	}
	for(int i=1;i<=N;++i) {
		andrs[i]=1;
		a[i]=i;
		central[i]=0;
		random_shuffle(re[i].begin(),re[i].end());
		random_shuffle(go[i].begin(),go[i].end());
		
	} 
	random_shuffle(a+1,a+N+1);
	for(int i=1;i<=sqr;++i) {
		++lock;cnw=0;
		dfs(a[i],re);
		for(int j=1;j<=N;++j) {
			andrs[j]=((andrs[j]==1)&&(vis[j]==lock)) ? 1:0;
		}
	}
	for(int i=1;i<=N;++i) {
		if(andrs[a[i]]!=1 || central[a[i]])continue;
		++lock;cnw=0;
		if(dfs(a[i],go)) {
			central[a[i]]=1;
			continue;
		}else {
			central[a[i]]=(cnw==N)?1:0;		
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i) {
	//	printf("%d\n",central[i]);
		ans+=central[i];
	}
	printf("%d\n",ans);
	return 0;
} 