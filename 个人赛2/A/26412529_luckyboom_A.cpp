#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int const maxn=55;
int q[maxn][maxn],ans=0,dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
bool vis[maxn][maxn];
void dfs(int x,int y){
	if(x<1||x>n||y<1||y>m)return ;
	//cout<<"haha2 "<<x<<' '<<y<<' '<<now<<endl;
	vis[x][y]=true;
	ans++;
	for(int i=0;i<4;i++){
		if(!(q[x][y]&(1<<i))&&!vis[x+dx[i]][y+dy[i]])dfs(x+dx[i],y+dy[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&q[i][j]);
		}
	int cou=0,shuchu=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!vis[i][j]){
				ans=0;
				dfs(i,j);
				if(ans>shuchu)shuchu=ans;
				cou++;
			}
		}
	cout<<cou<<endl<<shuchu<<endl;
	return 0;
}