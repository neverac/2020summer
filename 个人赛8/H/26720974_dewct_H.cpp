#include <bits/stdc++.h>
using namespace std;

const int maxn = 200020;

int num[maxn], f[maxn], g[maxn], ans;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (num[i - 1] < num[i])
            f[i] = f[i - 1] + 1;
        else
            f[i] = 1;
    }
    g[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (num[i] < num[i + 1])
            g[i] = g[i + 1] + 1;
        else
            g[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    for (int i = 2; i < n; i++)
        if (num[i - 1] < num[i + 1])
            ans = max(ans, f[i - 1] + g[i + 1]);
    cout << ans << endl;
    return 0;
}