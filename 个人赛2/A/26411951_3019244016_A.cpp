#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <ctime>
#include <list>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define dow(i,j,k) for(int i = j; i >= k; i--)
#define ez(i,x) for(int i = h[x]; i; i = e[i].next)
#define fi first
#define se second
#define MS(x) memset(x, 0, sizeof(x))
#pragma GCC optimize(3)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pi;

int n, m;
int a[55][55];
int vis[55][55];
int cnt, mx, tmp;
int fy[] = {-1,0,1,0};
int fx[] = {0,-1,0,1};

void dfs(int x, int y) {
   // cout << x << " " << y << endl;
	vis[x][y] = 1;
	tmp++;
	rep(i,0,3) {
		if (a[x][y] & (1 << i)) continue;
		if (!vis[x + fx[i]][y + fy[i]]) {
           
          
           // cout << x + fx[i] << " " << y + fy[i] << " " << vis[x+fx[i]][y+fy[i]] << endl;
			dfs(x + fx[i], y + fy[i]);
		}
	}
}
int main() {
	//ios::sync_with_stdio(0);
	cin >> n >> m;
	rep(i,1,n) rep(j,1,m) cin >> a[i][j];
	rep(i,0,m+1) vis[0][i] = vis[n+1][i] = 1;
    rep(i,0,n+1) vis[i][0] = vis[i][m+1] = 1;
	rep(i,1,n) rep(j,1,m) {
		if (!vis[i][j]) {
			tmp = 0;
			cnt++;
			dfs(i,j);
			mx = max(mx, tmp);
         //   cout << tmp << endl;
		}
       // cout << tmp << endl;
	}
	cout << cnt << endl << mx << endl;
}