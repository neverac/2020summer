#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 3010;
deque<int> q;
int n,m,a,b;
int h[SIZEN][SIZEN];
int g[SIZEN][SIZEN];
int f[SIZEN][SIZEN];
LL g0,x,y,z;
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    scanf("%lld%lld%lld%lld",&g0,&x,&y,&z);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            h[i][j] = g0;
            g0 = (g0*x+y)%z;
        }
    }
    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= m;j++)printf("%d ",h[i][j]);printf("\n");
    // }
    for(int i = 1;i <= n;i++){
        while(!q.empty())q.pop_front();
        for(int j = 1;j <= m;j++){
            while(!q.empty() && (h[i][q.front()] > h[i][j] || j-q.front()+1 > b ))q.pop_front();
            while(!q.empty() && (h[i][q.back()] > h[i][j]  || j-q.back()+ 1 > b))q.pop_back();
            q.push_front(j);
            if(j >= b)g[i][j] = h[i][q.back()];
        }
    }
    for(int j = 1;j <= m;j++){
        while(!q.empty())q.pop_front();
        for(int i = 1;i <= n;i++){
            while(!q.empty() && (g[q.front()][j] > g[i][j] || i-q.front()+1 > a))q.pop_front();
            while(!q.empty() && (g[q.back()][j] > g[i][j]  || i-q.back()+1 > a))q.pop_back();
            q.push_front(i);
            if(i >= a)f[i][j] = g[q.back()][j];
        }
    }
    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= m;j++)printf("%d ",f[i][j]);
    //     printf("\n");
    // }
    LL ans = 0;
    for(int i = a;i <= n;i++){
        for(int j = b;j <= m;j++)ans += f[i][j];
    }
    printf("%lld\n",ans);
    return 0;
}