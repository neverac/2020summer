#include <cstdio>
int a[55][55];
int vis[55][55];
int room;
void search(int x,int y)
{
	if(vis[x][y]) return;
	++room;
	vis[x][y]=1;
	if(!(a[x][y] & 1)) search(x,y-1);
	if(!(a[x][y] & 2)) search(x-1,y);
	if(!(a[x][y] & 4)) search(x,y+1);
	if(!(a[x][y] & 8)) search(x+1,y);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i)
	  for(int j = 1; j <= m; ++j)
	    scanf("%d",&a[i][j]);
	int cnt = 0,max = -1;
	for(int i = 1; i <= n; ++i)
	  for(int j = 1; j <= m; ++j)
	     if(!vis[i][j]){
		 	++cnt;
		 	room = 0;
		 	search(i,j); 
		 	if(room > max) max = room;
		 }
	printf("%d\n%d",cnt,max);
	return 0;
}