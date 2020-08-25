#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
template <typename T = int>
inline T read()
{
    T ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
template <typename T>
inline void write(T arg)
{
    if (arg < 0)
    {
        putchar('-');
        arg = ~arg + 1;
    }
    if (arg > 9) write(arg / 10);
    putchar(arg % 10 + '0');
}
int fa[100100];
struct Data{
    int first, second;
}edge[200100];
int cnt = 0;
inline bool cmp(const Data &x, const Data &y){
    return x.second == y.second ? x.first < y.first : x.second < y.second;
}
inline int ufs_find(int x){
    return x == fa[x] ? x : fa[x] = ufs_find(fa[x]);
}
inline void ufs_union(int x, int y){
    fa[ufs_find(y)] = ufs_find(x);
}
int deg[100100];
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        if (u > v) swap(u, v);
        ++cnt;
        edge[cnt].first = u;
        edge[cnt].second = v;
    }
    sort(edge + 1, edge + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        int u = edge[i].first, v = edge[i].second;
        if (ufs_find(u) != ufs_find(v))
        {
            ufs_union(u, v);
            ++deg[u];
            ++deg[v];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, deg[i]);
    write(ans);
    return 0;
}