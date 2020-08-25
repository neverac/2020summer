#include <bits/stdc++.h>
using namespace std;
const int MAXN=1E6+10;
int f[MAXN],income[MAXN];
int find(int i) {
	return i==f[i] ? i : (f[i]=find(f[i]));
}
vector<int>go[MAXN];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) {
		int x,y;scanf("%d%d",&x,&y);
		go[x].push_back(y);
		go[y].push_back(x);
	}
	for(int i=1;i<=n;++i) {
		f[i]=i;
		sort(go[i].begin(),go[i].end());
	}
	for(int i=1;i<=n;++i) {
		int len=go[i].size();
		for(int j=0;j<len;++j) {
			int from=i,to=go[i][j];
			if(to>from)break;
			int x=find(from);
			int y=find(to);
			if(x!=y) {
				f[y]=x;
				income[from]++;
				income[to]++;
			//	printf("[%d,%d]\n",from,to);
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;++i) {
		ans=max(ans,income[i]);
	}printf("%d\n",ans);
	return 0;
} 