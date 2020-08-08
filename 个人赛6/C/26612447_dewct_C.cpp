#include <bits/stdc++.h>
using namespace std;

int fa[233333];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i <= 100050; i++)
        fa[i] = i;
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y))
        {
            fa[find(x)] = find(y);
        }
        else
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}