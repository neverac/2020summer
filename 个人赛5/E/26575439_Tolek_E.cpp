#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n, ch[2000005][2], tot;
inline void insert(int& rt, int x, int p)
{
    if (rt == 0) rt = ++tot, ch[rt][0] = ch[rt][1] = 0;
    if (p == -1) return;
    insert(ch[rt][(x >> p) & 1], x, p - 1);
}
inline long long query(int rt, int x, int p)
{
    if (p == -1) return 0;
    int c = (x >> p) & 1;
    if (ch[rt][c]) return query(ch[rt][c], x, p - 1);
    return query(ch[rt][c ^ 1], x, p - 1) ^ (1ll << p);
}
long long f(vector<int> vec, int p)
{
    if (vec.size() == 0 || p < 0) return 0;
    vector<int> tmp[2];
    for (int i : vec) tmp[(i >> p) & 1].push_back(i);
    long long ans = 0;
    int rt = 0;
    if (tmp[0].size() && tmp[1].size()) {
        tot = 0, ans = 1l << (p + 1);
        for (int i : tmp[0]) insert(rt, i, 30);
        for (int i : tmp[1]) ans = min(ans, query(rt, i, 30));
    }
    // cout << ans << endl;
    return 1ll * ans + f(tmp[0], p - 1) + f(tmp[1], p - 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), vec.push_back(x);
    printf("%lld\n", f(vec, 30));
}