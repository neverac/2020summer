#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,m,a[maxn][maxn],vis[maxn][maxn],tmpm,cnt,mx;
void dfs(int i, int j){
	vis[i][j] = 1;
	tmpm ++;
	if(a[i][j] >= 8){
		a[i][j] -= 8;
	}else if(i+1 <= n && !vis[i+1][j]) dfs(i+1,j);
	
	if(a[i][j] >= 4){
		a[i][j] -= 4;
	}else if(j+1 <= m && !vis[i][j+1]) dfs(i,j+1);
	
	if(a[i][j] >= 2){
		a[i][j] -= 2;
	}else if(i-1 >= 1 && !vis[i-1][j]) dfs(i-1,j);
	
	if(a[i][j] >= 1){
	}else if(j-1 >= 1 && !vis[i][j-1]) dfs(i,j-1);
	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++ i){
		for(int j = 1;j <= m; ++ j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int ii = 1;ii <= n; ++ ii){
		for(int jj = 1;jj <= m; ++ jj){
			if(!vis[ii][jj]){
				cnt ++;
				tmpm = 0;
				dfs(ii,jj);
				if(tmpm > mx) mx = tmpm;
			}
		}
	}
	printf("%d\n%d\n",cnt,mx);
    return 0;
}