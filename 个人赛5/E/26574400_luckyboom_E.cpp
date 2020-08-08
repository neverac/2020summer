#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 7;

int L[maxn * 40],R[maxn * 40];
int ch[maxn * 40][2],tot;
int n,root;
int a[maxn];

void Insert(int &now,int x,int dep) {
    if(!now) now = ++tot;
    L[now] = min(L[now],x);R[now] = max(R[now],x);
    if(dep < 0) return;
    int bit = a[x] >> dep & 1;
    Insert(ch[now][bit],x,dep - 1);
}

ll query(int now,int val,int dep) {
    if(dep < 0) return 0;
    int bit = (val >> dep) & 1;
    if(ch[now][bit]) return query(ch[now][bit],val,dep - 1);
    return query(ch[now][bit ^ 1],val,dep - 1) + (1 << dep);
}

ll dfs(int now,int dep) {
    if(dep < 0) return 0;
    if(R[ch[now][0]] && R[ch[now][1]]) {
        ll mi = INF;
        for(int i = L[ch[now][0]];i <= R[ch[now][0]];i++) {
            mi = min(mi,query(ch[now][1],a[i],dep - 1));
        }
        return dfs(ch[now][0],dep - 1) + mi + dfs(ch[now][1],dep - 1) + (1 << dep);
    }
    if(R[ch[now][0]]) return dfs(ch[now][0],dep - 1);
    if(R[ch[now][1]]) return dfs(ch[now][1],dep - 1);
    return 0;
}

int main() {
    int n;scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a + 1,a + 1 + n);
    memset(L,0x3f,sizeof(L));
    for(int i = 1;i <= n;i++) Insert(root, i, 30);
    printf("%lld\n",dfs(root,30));
    return 0;
}


