/*
 *powered by caibiCH2
 *create at 2020-02-05 17:30:13
 */
#include <bits/stdc++.h>
#define elif else if
//#define max(x,y) ((x)>(y)?(x):(y))
//#define min(x,y) ((x)<(y)?(x):(y))
#define INF 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int g[210][210];
int kw[210],d[210];
struct msp{
	int x,y;
};
vector<msp>ans;
struct treeNode{
	int fa,cnt;
	vector<int>edge;
}tree[210];

int father(int x){
	if(kw[x]!=x){
		return kw[x]=father(kw[x]);
	}
	else return x;
}
void buildTree(int x,int fa){
	for(auto p:tree[x].edge){
		if(p!=fa){
			tree[p].fa=x;
			buildTree(p,x);
		}
	}
	if(tree[x].cnt%2==0)++tree[fa].cnt;
	else if(fa)ans.push_back({min(x,fa),max(x,fa)});
}

signed main (/*int argc, char const* argv[]*/){
	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i+=1){
		int x,y;cin>>x>>y;
		g[x][y]=g[y][x]=1;
		++d[x],++d[y];
	}
	if(n%2==1){
		for(int i=1;i<=n;i+=1){
			for(int j=i+1;j<=n;j+=1){
				if(!g[i][j])ans.push_back({i,j});
			}
		}
		cout<<ans.size()<<'\n';
		for(auto i:ans)cout<<i.x<<' '<<i.y<<'\n';
		return 0;
	}
	for(int p=1;p<=n;p+=1){
		if(d[p]==0){
			int flag=0,t1,t2;
			for(int i=1;i<=n;i+=1){
				for(int j=i+1;j<=n;j+=1){
					if(!g[i][j]&&i!=p&&j!=p){
						flag=1,t1=i,t2=j;break;
					}
				}
				if(flag)break;
			}
			if(flag){
				ans.push_back({min(p,t1),max(p,t1)}),ans.push_back({min(p,t2),max(p,t2)});
				for(int i=1;i<=n;i+=1){
					for(int j=i+1;j<=n;j+=1){
						if(!g[i][j]&&i!=p&&j!=p&&(i!=t1||j!=t2)){
							ans.push_back({i,j});
						}
					}
				}
				cout<<ans.size()<<'\n';
				for(auto i:ans)cout<<i.x<<' '<<i.y<<'\n';
				return 0;
			}
			else{
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i+=1){
		kw[i]=i;
	}
	for(int i=1;i<=n;i+=1){
		for(int j=i+1;j<=n;j+=1){
			if(!g[i][j]){
				if(father(i)!=father(j)){
					kw[father(i)]=father(j);
					tree[i].edge.push_back(j);
					tree[j].edge.push_back(i);
				}
				else ans.push_back({i,j});
			}
		}
	}
	for(int i=1;i<=n;i+=1){
		if(tree[i].fa==0){
			buildTree(i,0);
			if(tree[0].cnt){
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.x<<' '<<i.y<<'\n';
	return 0;
}