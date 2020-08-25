#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int maxn= 510;
int n,m;
ll xx[maxn],yy[maxn],r,now;
ll a[maxn][maxn];
char s[2];
int t;
inline void init(){


    cin >> n >> m >> t;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            a[i][j] %= mod;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   init();
    for (int i=1;i<=t;i++){
        cin >> s >> r >> now;
        if(s[0] == 'r') xx[r] = now;
        else yy[r] = now;
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans = (ans + max(xx[i], yy[j]) % mod * a[i][j] % mod) % mod;
        }
    }
    cout << ans << endl;
}
