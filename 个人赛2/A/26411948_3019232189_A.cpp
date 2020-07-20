#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int n,m,ans,mx;
int a[56][56],tx[10],ty[10];
bool fla[56][56];

int dfs(int x,int y){
    fla[x][y]=1;
    int tt=a[x][y],cnt=0;
    for(int i=1;i<=8;i<<=1)
        if( !(a[x][y]&i) && !fla[x+tx[i]][y+ty[i]] )
            cnt+=dfs(x+tx[i],y+ty[i]);
    return cnt+1;
}

int main(){
    tx[1]=0; ty[1]=-1;
    tx[2]=-1; ty[2]=0;
    tx[4]=0; ty[4]=1;
    tx[8]=1; ty[8]=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!fla[i][j]){
                ++ans;
                mx=max(mx,dfs(i,j));
            }
    cout<<ans<<'\n'<<mx<<'\n';


    //while(1);
}
