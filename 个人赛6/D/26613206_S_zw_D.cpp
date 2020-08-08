#include<stdio.h>
#include<string.h>
#include<string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long 
#define N 1000010
#define mid (l+r)/2
#define lc (x<<1)
#define rc (x<<1)|1
#define tozero(x) memset(x,0,sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e9+7;
using namespace std;

ll start[11][105][105];

ll dp[11][105][105];

ll n,q,c;

void dpInit(){
    for(ll i=0;i<=10;i++){
        for(ll j=1;j<=100;j++){
            for(ll k=1;k<=100;k++){
                dp[i][j][k] = dp[i][j-1][k] + dp[i][j][k-1] - dp[i][j-1][k-1] + start[i][j][k];
            }
        }
    }
}

ll getS(ll x1,ll y1,ll x2,ll y2,ll t){
    ll ans = 0;
    for(ll i=0;i<=c;i++){
        ll num = dp[i][x2][y2] - dp[i][x1-1][y2] - dp[i][x2][y1-1] + dp[i][x1-1][y1-1];
        ll light = (i+t)%(c+1);
        ans += num * light;
    }
    return ans;
}

int main(){
    scanf("%lld %lld %lld",&n,&q,&c);
    for(ll i=1;i<=n;i++){
        ll xi,yi,si;
        scanf("%lld %lld %lld",&xi,&yi,&si);
        start[si][xi][yi]++;
    }
    dpInit();
    for(ll i=1;i<=q;i++){
        ll ti,x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld %lld",&ti,&x1,&y1,&x2,&y2);
        printf("%lld\n",getS(x1,y1,x2,y2,ti));
    }
    return 0;
}