#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector> 
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long
#define N 600
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
const ll mod = 998244353;
using namespace std;
ll n, m, k;
ll a[N][N];
ll r_last[N],c_last[N];

int main ()
{
    scanf("%lld %lld %lld", &n, &m,&k);
    for (ll i = 1; i <= n;i++){
        for (ll j = 1; j <= m;j++){
            scanf("%lld", &a[i][j]);
            a[i][j] %= mod;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= k;i++){
        char c[N];
        ll p, t;
        scanf("%s", c);
        scanf("%lld %lld", &p, &t);
        if(c[0] == 'r'){
            r_last[p] = t;
        }else{
            c_last[p] = t;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            ans += max(r_last[i], c_last[j]) % mod * a[i][j] % mod;
            ans %= mod;
        }
    }
    printf("%lld\n", ans % mod);
    return 0;
}