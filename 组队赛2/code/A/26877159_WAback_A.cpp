#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
const int SIZEN = 200010;
typedef long long LL;
#define mid ((l+r) >> 1)
int N,M;
int a[SIZEN];
struct Car{
	bool type;//1长度为3 , 0长度为2
	bool to;//1朝下 , 0朝右
	int x,y;
}c[20];
int cnt = 0;
int str[10][10];
int tmp[10][10];
bool vis[10][10];
int ans = 0;
void process(){
	for(int i = 1;i <= 6;i++){
		for(int j = 1;j <= 6;j++){
			if(vis[i][j])continue;
			if(str[i][j] == 0)continue;
			int x = str[i][j];
			cnt++;
			c[x].x = i;c[x].y = j;
			if(str[i+1][j] == x && str[i+2][j] == x){
				c[x].type = 1;
				c[x].to = 1;
				vis[i+1][j] = vis[i+2][j] = true;
			}
			else if(str[i][j+1] == x && str[i][j+2] == x){
				c[x].type = 1;
				c[x].to = 0;
				vis[i][j+1] = vis[i][j+2] = true;
			}
			else if(str[i+1][j] == x){
				c[x].type = 0;
				c[x].to = 1;
				vis[i+1][j] = true;
			}
			else if(str[i][j+1] == x){
				c[x].type = 0;
				c[x].to = 0;
				vis[i][j+1] = true;
			}
		}
	}
}
bool Check(){
	for(int i = 0;i <= 7;i++)for(int j = 0;j <= 7;j++)tmp[i][j] = 0;
	for(int i = 0;i <= 7;i++)tmp[0][i] = tmp[i][0] = tmp[7][i] = tmp[i][7] = 100;
	for(int i = 1;i <= cnt;i++){
		int len = 2 + c[i].type;
		int xx = c[i].x,yy = c[i].y;
		if(c[i].to == 1){
			for(int j = xx;j <= xx + len - 1;j++){
				if(tmp[j][yy])return true;
				tmp[j][yy] = i;
			}
		}
		else{
			for(int j = yy;j <= yy + len - 1;j++){
				if(tmp[xx][j])return true;
				tmp[xx][j] = i;
			}
		}
	}
	return false;
}
bool Judge(int m){
	for(int i = 0;i <= 7;i++)for(int j = 0;j <= 7;j++)tmp[i][j] = 0;
	for(int i = 1;i <= 7;i++)tmp[0][i] = tmp[i][0] = tmp[7][i] = tmp[i][7] = 100;
	for(int i = 2;i <= cnt;i++){
		int len = 2 + c[i].type;
		int xx = c[i].x,yy = c[i].y;
		if(c[i].to == 1){
			for(int j = xx;j <= xx + len - 1;j++)tmp[j][yy] = i;
		}
		else{
			for(int j = yy;j <= yy + len - 1;j++)tmp[xx][j] = i;
		}
	}
	int xx = c[1].x,yy = c[1].y;
	if(xx != 3)return false;
	for(int i = yy;i <= 6;i++){
		if(tmp[xx][i])return false;
		m++;
	}
	if(ans == -1)ans = m;
	ans = min(ans,m);
	return true;
}
void dfs(int x){
	if(x + 7 - c[1].y > 11)return;
	if(ans!=-1 && x-1+7-c[1].y >= ans)return;
	if(Check())return;
	if(Judge(x-1)){
		return;
	}
	for(int i = 1;i <= cnt;i++){
		int xx = c[i].x,yy = c[i].y;
		if(c[i].to == 1){
			c[i].x = xx-1;
			dfs(x+1);
			c[i].x = xx+1;
			dfs(x+1);
			c[i].x = xx;
		}
		else{
			c[i].y = yy-1;
			dfs(x+1);
			c[i].y = yy+1;
			dfs(x+1);
			c[i].y = yy;
		}
	}
}
int main(){
	for(int i = 1;i <= 6;i++)str[0][i] = str[i][0] = str[7][i] = str[i][7] = 100;
	str[0][0] = str[0][7] = str[7][0] = str[7][7] = 100;
	for(int i = 1;i <= 6;i++)for(int j = 1; j<=6;j++)scanf("%d",&str[i][j]);
	process();
	//for(int i = 1;i <= cnt;i++)printf("(%d,%d,%d,%d,%d)\n",i,c[i].x,c[i].y,c[i].to,c[i].type);
	if(c[1].to == 1 || c[1].x != 3){
		puts("-1");
		return 0;
	}
	else {
		ans = -1;
		dfs(1);
		printf("%d\n",ans);
	}
	//printf("time_used = %.3f\n",1.*clock()/CLOCKS_PER_SEC);
	return 0;
}
/*
2 2 0 0 0 7
3 0 0 5 0 7
3 1 1 5 0 7
3 0 0 5 0 0
4 0 0 0 8 8
4 0 6 6 6 0

0 0 0 0 0 0
0 0 5 0 0 0
1 1 5 6 7 0
0 0 5 6 7 0
0 2 2 0 0 4
3 3 3 0 0 4

0 2 0 6 6 0
0 2 0 0 7 0
0 3 1 1 7 0
0 3 4 4 8 0
0 5 5 5 8 0
0 0 0 0 0 0
*/