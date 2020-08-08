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
#define N 100006
using namespace std;

int n,q,c;
int s[N],x[N],y[N];
int pre[106][106][16];

int main(){
    int x1,y1,x2,y2,tt;
    ll ans,temp;
    scanf("%d%d%d",&n,&q,&c);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&x[i],&y[i],&s[i]);
        ++pre[x[i]][y[i]][s[i]];
    }
    for(int i=1;i<=100;++i)
        for(int j=1;j<=100;++j)
            for(int k=0;k<=10;++k)
                pre[i][j][k]+=(pre[i-1][j][k]+pre[i][j-1][k]-pre[i-1][j-1][k]);
    
    for(int i=1;i<=q;++i){
        scanf("%d%d%d%d%d",&tt,&x1,&y1,&x2,&y2);
        ans=0;
        for(int k=0;k<=c;++k){
            temp=pre[x2][y2][k]-pre[x1-1][y2][k]-pre[x2][y1-1][k]+pre[x1-1][y1-1][k];
            //printf("k=%d temp=%lld\n",k,temp);
            temp=temp*((k+tt)%(c+1));
            ans+=temp;
        }
        printf("%lld\n",ans);
    }

    //while(1);
}
