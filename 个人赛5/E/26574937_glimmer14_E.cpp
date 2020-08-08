#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 7;
int ch[N * 30][2], siz[N * 30], cnt, col, rt[N * 30];

ll ans;
vector<int> dsr[N * 30];

void insert(int x)
{
    int p = 0;
    for (int i = 1 << 29; i; i >>= 1)
    {
        bool k = x & i;
        siz[p] ++;
        if (!ch[p][k])
            ch[p][k] = ++cnt;
        p = ch[p][k];
    }
    siz[p] ++;
    if (!rt[p])
        rt[p] = ++ col;
    dsr[rt[p]].push_back(x);
}

int query(int rt, int init, int x)
{
    int p = rt, ans = 0;
    for (int i = 1 << init; i; i >>= 1)
    {
        bool k = x & i;
        if (ch[p][k])
            p = ch[p][k];
        else  
            p = ch[p][!k], ans |= i;
    }
    return ans;
}

void dfs(int p, int dep)
{
    if (!ch[p][0] && !ch[p][1])
        return;
    if (!ch[p][0] || !ch[p][1])
    {
        dfs(ch[p][0] | ch[p][1], dep - 1);
        rt[p] = rt[ch[p][0] | ch[p][1]];
    }
    else
    {
        int k = siz[ch[p][0]] < siz[ch[p][1]];
        dfs(ch[p][0], dep - 1);
        dfs(ch[p][1], dep - 1);
        rt[p] = rt[ch[p][k]];
        int tmp = INT_MAX;
        int nb = ch[p][!k];
        ch[p][!k] = 0;
        for (int x : dsr[rt[nb]])
        {
            tmp = min(tmp, query(p, dep, x));
            dsr[rt[p]].push_back(x);
        }
        ans += tmp;
        ch[p][!k] = nb;
    }
    
}


int main()
{
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        insert(x);
    }
    dfs(0, 29);
    printf("%lld\n", ans);
    return 0;
}