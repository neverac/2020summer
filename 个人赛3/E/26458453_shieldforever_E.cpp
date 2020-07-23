#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long LL;
LL f[3][N], h[3][N], n;

void init(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[1][i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[2][i]);
    return ;
}

void solve(){
    f[1][1] = h[1][1], f[2][1] = h[2][1];
    LL m1 = f[1][1], m2 = f[2][1];
    for(int i = 2; i <= n; i++){
        f[1][i] = m2 + h[1][i];
        f[2][i] = m1 + h[2][i];
        m1 = max(m1, f[1][i]), m2 = max(m2, f[2][i]);
    }
    printf("%lld\n", max(m1, m2));
    return ;
}

int main(){
    init();
    solve();
    return 0;
}