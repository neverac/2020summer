#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long  LL;
const LL base = 1e5;
struct node{
    int to, from;
    LL w;
}e[N << 1];
int head[N], f[N];
int n, m, len = 0;
void add_edge(int u, int v, LL w){
    e[++len].from = u; e[len].to = v; e[len].w = w; return ;
}
void init(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        LL x, y;
        scanf("%lld%lld", &x, &y);
        LL w = max(x, y) * base + min(x, y);
        add_edge(x, y, w);
    }
    // cout<<e[5].w<<endl;
    return ;
}
bool cmp(node a, node b){
    return a.w < b.w;
}
int findx(int x){
    if(f[x] == x) return x;
    else return f[x] = findx(f[x]);
}
int deg[N];
void solve(){
    // cout<<m<<endl;
    sort(e + 1, e + 1 + m, cmp);
    for(int i = 1; i <= n; i++) f[i] = i;
    int o = 0;
    for(int i = 1; i <= m; i++){
        // cout<<e[i].from<<' '<<e[i].to<<' '<<e[i].w<<endl;
        int fx = findx(e[i].from), fy = findx(e[i].to);
        if(fx != fy){
            ++o;
            deg[e[i].to]++; deg[e[i].from]++;
            f[fx] = fy;
            if(o == n - 1) break;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] > ans) ans = deg[i];
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    init();
    solve();
    return 0;
}