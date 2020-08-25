#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
typedef long long ll;
vector<pair<int, int>> vec;
int n, m, fa[N], deg[N];
int cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
int ff(int x)
{
    return fa[x] == x ? x : fa[x] = ff(fa[x]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        vec.push_back(make_pair(x, y));
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size(); i++) {
        if (ff(vec[i].first) != ff(vec[i].second)) {
            fa[ff(vec[i].first)] = ff(vec[i].second);
            ++deg[vec[i].first];
            ++deg[vec[i].second];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, deg[i]);
    printf("%d", ans);
    return 0;
}