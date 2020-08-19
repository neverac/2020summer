#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 200006
using namespace std;

int n,m;
ll p[N];
int pre[3][N*2],nxt[3][N*2],ind[3][N*2],cnt[3];
bool vis[N];

bool cmp(int x,int y){
    return p[x]<p[y];
}

int main(){
    int temp,now,tt;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&p[i]);
    for(int i=1;i<=n;++i){
        scanf("%d",&temp);
        --temp;
        ind[temp][++cnt[temp]]=i;
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&temp);
        --temp;
        ind[temp][++cnt[temp]]=i;
    }
    for(int i=0;i<3;++i){
        nxt[i][0]=1;
        pre[i][1]=0;
        for(int j=1;j<=cnt[i];++j){
            nxt[i][j]=j+1;
            pre[i][j+1]=j;
        }
    }

    for(int i=0;i<3;++i)
        sort(ind[i]+1,ind[i]+1+cnt[i],cmp);

    /*for(int i=0;i<3;++i)
        printf("%d ",cnt[i]);
    cout<<'\n';

    for(int i=0;i<3;++i){
        for(int j=1;j<=cnt[i];++j)
            printf("%d ",ind[i][j]);
        cout<<'\n';
    }*/
    
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d",&temp);
        --temp;
        tt=0;
        now=nxt[temp][0];
        while(now<=cnt[temp]){
            if(!vis[ind[temp][now]]){
                vis[ind[temp][now]]=1;
                tt=1;
                printf("%d ",p[ind[temp][now]]);
                nxt[temp][pre[temp][now]]=nxt[temp][now];
                pre[temp][nxt[temp][now]]=pre[temp][now];
                break;
            }
            else{
                nxt[temp][pre[temp][now]]=nxt[temp][now];
                pre[temp][nxt[temp][now]]=pre[temp][now];
                now=nxt[temp][now];
            }
        }
        if(!tt)
            printf("-1 ");
    }
    //while(1);
}
