#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
typedef long long ll;
struct Edge
{
    int next, to;
} edge[N << 1];
int head[N], cnt = 1, n, sz[N];
vector<int> ans;
inline void add(int x, int y)
{
    edge[cnt].next = head[x], edge[cnt].to = y, head[x] = cnt++;
}
void DFS(int x, int fa)
{
    int maxn = 0;
    sz[x] = 1;
    for (int i = head[x]; i; i = edge[i].next) {
        if (edge[i].to == fa) continue;
        DFS(edge[i].to, x), sz[x] += sz[edge[i].to], maxn = max(maxn, sz[edge[i].to]);
    }
    maxn = max(maxn, n - sz[x]);
    if (maxn < n - maxn) ans.push_back(x);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if (x) add(x, i), add(i, x);
    }
    DFS(1, 0);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
    return 0;
}