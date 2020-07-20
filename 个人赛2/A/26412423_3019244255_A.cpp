#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int m,n,ans,cnt,max0;
bool f[100][100],mark[100][100][4];
int map[105][105];
int k[4]= {0,1,0,-1},l[4]= {1,0,-1,0};
bool check(int a,int b,int x) {
	if(a<m&&b<n&&a>=0&&b>=0&&mark[a][b][x]&&!f[a][b]) return 1;
	return 0;
}
void dfs(int r,int c) { 
	for(int i=0; i<4; i++)
		if(check(r+k[i],c+l[i],i)) {
			f[r+k[i]][c+l[i]]=1;
			cnt++;
			dfs(r+k[i],c+l[i]);
		}
}
int main() {
	cin>>m>>n;
	for(int i=0; i<m; i++) 
		for(int j=0; j<n; j++) {
			cin>>map[i][j];
			if(!(map[i][j]&1)) mark[i][j][0]=1;
			if(!(map[i][j]&2)) mark[i][j][1]=1;
			if(!(map[i][j]&4)) mark[i][j][2]=1;
			if(!(map[i][j]&8)) mark[i][j][3]=1;
		}
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(!f[i][j]) {
				f[i][j]=1;
				cnt=1;
				dfs(i,j);
				if(cnt>max0) max0=cnt; 
				ans++;
			}
	cout<<ans<<endl;
	cout<<max0<<endl;
}
