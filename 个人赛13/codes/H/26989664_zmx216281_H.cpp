#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int mod = 998244353;
ll a[510][510],rt[510],ct[510];
int main() {
    ll n,m,k,x,t;
    char c;
    ll ans = 0;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i = 1;i <= k;i++) {
        cin >> c;
        scanf("%lld%lld",&x,&t);
        if(c == 'r'){
            rt[x] = t;
        }
        else{
            ct[x] = t;
        }
    }
    
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ll t = max(rt[i],ct[j]);
            ans = (ans + ((__int128)a[i][j]*t)%mod)%mod;
        }
    }
    printf("%lld\n",ans%mod);
    return 0;
}
