#include <bits/stdc++.h>

#define N 100005
using namespace std;
struct Edge
{
    int to, next;
} edge[200005];
int head[N], cnt = 1, id[N], n, m, vis[N], x, y, DFNt = 1, DFN[N], LOW[N], ID = 1;
int all[N], out[N];
stack<int> sta;
queue<int> que;

inline void add(int x, int y)
{
    edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

void tarjan(int x)
{
    if (DFN[x]) return;
    DFN[x] = LOW[x] = DFNt++, vis[x] = 1, sta.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        if (vis[edge[i].to])
            LOW[x] = min(LOW[x], DFN[edge[i].to]);
        else if (!DFN[edge[i].to])
            tarjan(edge[i].to), LOW[x] = min(LOW[x], LOW[edge[i].to]);
    }
    if (DFN[x] == LOW[x]) {
        int t;
        do
            vis[sta.top()] = 0, id[t = sta.top()] = ID, sta.pop(), all[ID]++;  //all计数该强连通分量有几个点
        while (t != x);
        ID++;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d", &x, &y), add(x, y);
    for (int i = 1; i <= n; i++) tarjan(i);
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = edge[j].next) {
            if (id[i] != id[edge[j].to]) ++out[id[edge[j].to]];
        }
    }
    int tot = 0, who;
    for (int i = 1; i < ID; i++) {
        if (out[i] == 0) ++tot, who = i;
    }
    if (tot > 1) {
        printf("0");
    } else {
        printf("%d", all[who]);
    }
    return 0;
}