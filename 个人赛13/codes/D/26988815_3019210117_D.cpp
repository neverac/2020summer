#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int>lin[200005];
int fa[200005],cnt[200005],n,m;
int getfa(int x){
	if(fa[x]!=x){
        fa[x]=getfa(fa[x]);
    }
	return fa[x];
}
void sol(){
	for(int i=1;i<=n;i++){
        fa[i]=i;
        cnt[i]=0;
    }
	int ans=0;
	for(int i=0;i<m;i++){
		int x=lin[i].first,y=lin[i].second,fx=getfa(x),fy=getfa(y);
		if(fx!=fy){
			fa[fx]=fy;
			cnt[x]++;
            cnt[y]++;
			ans=max(ans,max(cnt[x],cnt[y]));
		}
	}
	printf("%d\n",ans);
}

int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		lin[i].first=max(u,v); 
		lin[i].second=min(u,v);
	} 
	sort(lin,lin+m);
	sol();
	return 0;
 } 