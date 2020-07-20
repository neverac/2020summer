#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define maxn 70
#define INF 0x7fffffffffffffff
using namespace std;
int m,n,a[maxn][maxn],vis[maxn][maxn],tot,cnt,maxx;
//double x2,x3,y2,y3,h,a,k,vis;
////long long lsl,ovo,x,y,m,n,l,r,mid;
//bool isOK(){
//  return (mid - m -n -mid/x/y >= (lsl > m ? lsl - m : 0) + (ovo > n ? ovo - n : 0));
//}
void dfs(int x,int y){
    if (vis[x][y]) return ;
    tot++;
    vis[x][y] = cnt;
    //nextone
    if ((a[x][y]&1) == 0) dfs(x,y-1);
    if ((a[x][y]&2) == 0) dfs(x-1,y);
    if ((a[x][y]&4) == 0) dfs(x,y+1);
    if ((a[x][y]&8) == 0) dfs(x+1,y);
}
void init(){
    cin >> m >> n;
    for (int i =0;i<m;i++)
        for (int j = 0;j<n;j++)
            cin >> a[i][j];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    init();
        //dfs sou
    for (int i=0;i<m;i++)
        for (int j = 0;j<n;j++){
            if (!vis[i][j]){
                tot = 0;
                cnt ++;
                dfs(i,j);
                if (tot > maxx) maxx = tot;

            }
        }
    cout << cnt << endl << maxx << endl;

    return 0;
}