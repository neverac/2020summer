#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};
int n,m;
struct node{
    int x;
	int y;
	int d;
    bool operator < (const node &k)const
	{
        return d > k.d;
    }
};
priority_queue <node> q;
int func(){
    while(!q.empty()){
        node k = q.top();
        q.pop();
        if(mp[k.x][k.y]=='2') return k.d;
 		for(int i=0 ; i<=3; ++i)
		 {
            int x = xx[i] + k.x;
            int y = yy[i] + k.y;
            if(!vis[x][y] && x>=1 && x<=n && y>=1 && y<=m)
			{
                vis[x][y] = true;
                node t;
                t.x = x;
                t.y = y;
                t.d = k.d + 1;
                q.push(t);
            }
        }
    }
 	return -1;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    n = read();
    m = read();
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j){
            cin>>mp[i][j];
            if(mp[i][j] == '1')
			{
				node t;
				t.x= i;
				t.y= j;
				t.d= 1;
                q.push(t);
                vis[i][j] = true;
            }
        }
    int res = func();
    cout<<res<<endl;
 	return 0;
}