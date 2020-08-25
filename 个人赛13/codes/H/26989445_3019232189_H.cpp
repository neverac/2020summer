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
#define N 506
#define M 998244353
using namespace std;

int n,m,k;
ll a[N][N],mx1[N],mx2[N],las[N][N],ans;
char cc[10];

int main(){
    ll t1,t2;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            scanf("%lld",&a[i][j]);
            a[i][j]%=M;
        }
    for(int i=1;i<=k;++i){
        scanf("%s%lld%lld",cc,&t1,&t2);
        if(cc[0]=='r')
            mx1[t1]=t2;
        else
            mx2[t1]=t2;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            las[i][j]=mx1[i];
    for(int j=1;j<=m;++j)
        for(int i=1;i<=n;++i)
            las[i][j]=max(las[i][j],mx2[j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans=(ans+las[i][j]%M*a[i][j]%M)%M;
    printf("%lld\n",ans);
    //while(1);
}
