#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long LL;
LL b[N], g[N];
LL x = 0LL, y = 0LL, sb = 0, sg = 0;
LL ans = 0;
int n, m;

bool solve(){
    for(int i = 1; i <= m; i++){
        if(x > g[i]) return false;
    }
    for(int i = 1; i <= n; i++){
        if(y < b[i]) return false;
    }
    int p = 0;
    for(int i = 1; i <= m; i++){
        LL sum = 0LL;
        sum += sb;
        if(x < g[i]) sum += g[i] - x, ++p;
        ans += sum;
    }
    sort(b + 1, b + 1 + n);
    sort(g + 1, g + 1 + m);
    int o = 1;
    while(g[o] <= x && o <= m) ++o;
    if(o > m || p < m) return true;
    ans += b[n] - b[n - 1];
    return true;
}

int main(){
    cin>>n>>m;
    x = 0LL;
    y = 1000000000LL;
    for(int i = 1; i <= n; i++) scanf("%lld", &b[i]), x = max(x, b[i]), sb += b[i];
    for(int j = 1; j <= m; j++) scanf("%lld", &g[j]), y = min(y, g[j]), sg += g[j];
    if(solve()){
        printf("%lld\n", ans);
    }
    else printf("-1\n");
    return 0;
}