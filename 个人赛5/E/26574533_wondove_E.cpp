#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 200000;
const LL INF = 1e18;
 
int n, a[N+5], A[40]; LL bin[40], ans;
struct Trie {
    int ch[N*35][2], bit[N*35+5], pos;
    vector<int>key[N*35];
    void insert(int t) {
        int u = 0; key[u].push_back(t);
        for (int i = 35; i >= 1; i--) {
            if (ch[u][A[i]] == 0) ch[u][A[i]] = ++pos; u = ch[u][A[i]];
            t -= bin[i-1]*A[i], key[u].push_back(t), bit[u] = i;
        }
    }
    LL qry(int u, int t) {
        LL ans = 0;
        for (int i = 1; i <= bit[u]-1; i++) A[i] = t%2, t /= 2;
        for (int i = bit[u]-1; i >= 1; i--) {
            if (ch[u][A[i]] != 0) u = ch[u][A[i]];
            else u = ch[u][A[i]^1], ans += bin[bit[u]-1];
        }
        return ans;
    }
    LL query(int o) {
        if (key[o].size() == 1) return 0;
        if (ch[o][0]) ans += query(ch[o][0]);
        if (ch[o][1]) ans += query(ch[o][1]);
        if (!ch[o][0] || !ch[o][1]) return 0;
        LL tmp = INF; int flag = 0;
        if (key[ch[o][0]].size() > key[ch[o][1]].size()) flag = 1;
        int sz = key[ch[o][flag]].size();
        for (int i = 0; i < sz; i++) tmp = min(qry(ch[o][flag^1], key[ch[o][flag]][i]), tmp);
        return tmp+bin[bit[o]-2];
    }
}T;
 
void work() {
    bin[0] = 1; for (int i = 1; i <= 35; i++) bin[i] = (bin[i-1]<<1);
    sort(a+1, a+n+1); n = unique(a+1, a+n+1)-a-1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, t = a[i]; j <= 35; j++) A[j] = t%2, t /= 2; T.insert(a[i]);
    }
    ans += T.query(0); printf("%lld\n", ans);
}
struct Edge{
    int u,v,w,next;
}E[N<<1];
int ecnt=0,head[N];
void addedge(int u,int v,int w){
    E[++ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt;
}
void Addedge(int u,int v,int w){
    addedge(u,v,w);
    addedge(v,u,w);
}
void dfs(int x,int fx){
    for(int i=head[x];i;i=E[i].next){
        int v=E[i].v;
        if(v==fx) continue;
        a[v]=a[x]^E[i].w;
        dfs(v,x);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	work(); 
    return 0;
}