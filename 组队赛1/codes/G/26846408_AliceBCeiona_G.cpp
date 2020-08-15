#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
const int MAXN = 100000 + 10;
int tree[MAXN], c[MAXN], a[MAXN];
int n;
int f[MAXN], g[MAXN];
void add(int x)
{
    while (x)
    {
        tree[x] += 1;
        x -= lowbit(x);
    }
}
int sum(int x)
{
    int ans = 0;
    while (x <= MAXN)
    {
        ans += tree[x];
        x += lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = sum(a[i] + 1);
        add(a[i]);
    }
    memset(tree, 0, sizeof tree);
    for (int i = n; i >= 1; i--)
    {
        g[i] = sum(a[i] + 1);
        add(a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = ans + min(f[i], g[i]);
    cout << ans << endl;
    return 0;
}