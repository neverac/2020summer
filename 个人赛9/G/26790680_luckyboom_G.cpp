#include <bits/stdc++.h>
using namespace std;
int const maxn=2e5+7;
int n,ans[maxn];
bool vis[maxn];

struct node{
	int w;
	int c;
	
};
bool cmp(node x,node y){
	return x.w<y.w;
}
vector<node>q[4];
int col[maxn],fr[maxn],ba[maxn],m,head[4];
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&col[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&fr[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&ba[i]);
	}
	for(int i=1;i<=n;i++){
		q[fr[i]].push_back((node){col[i],i});
		q[ba[i]].push_back((node){col[i],i});
	}
	for(int i=1;i<=3;i++){
		sort(q[i].begin(),q[i].end(),cmp);
	}
	scanf("%d",&m);
	for(int i=1;i<=3;i++)head[i]=0;
	node a;
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		bool flag=false;
		while(head[x]<q[x].size()){
			a=q[x][head[x]];
			if(!vis[a.c]){
				ans[i]=a.w;
				vis[a.c]=true;
				flag=true;
				break;
			}
			head[x]++;
		}
		if(!flag)ans[i]=-1;
	}
	for(int i=1;i<m;i++)printf("%d ",ans[i]);
		cout<<ans[m]<<endl;
	return 0;
}