#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<set>
#include<unordered_map>
#define Maxn 1000007
#define ll long long

using namespace std;

ll a[505][505];
ll we[505][505];//记录最后一次割草的时间
ll mod=998244353;
int main() {
    ll n,m,k,xx,tt;
    ll ans=0;
    char c;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            a[i][j]%=mod;
        }
    }
    for(ll p=1;p<=k;p++){

        cin>>c>>xx>>tt;
        if(c=='r'){
            for(ll i=1;i<=m;i++)
            we[xx][i]=max(we[xx][i],tt);
        }
        if(c=='c'){
            for(ll i=1;i<=n;i++)
            we[i][xx]=max(we[i][xx],tt);
        }
    }
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=m;j++){
        ans+=((a[i][j]%mod)*(we[i][j]%mod))%mod;

    }
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
