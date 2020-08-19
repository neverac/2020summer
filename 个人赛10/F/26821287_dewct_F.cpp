#include <bits/stdc++.h>
using namespace std;

int num[100050];

int dfs(int l, int r, int c)
{
    if (c < 0)
        return 0;
    int ls = 1 << c;
    int p = 0;
    for (int i = l; i <= r; i++)
    {
        if (num[i] & ls)
        {
            p = i;
            break;
        }
    }
    if (p == 0 || p == l)
        return dfs(l, r, c - 1);
    return ls | min(dfs(l, p - 1, c - 1), dfs(p, r, c));
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    cout << dfs(1, n, 30) << endl;
    return 0;
}