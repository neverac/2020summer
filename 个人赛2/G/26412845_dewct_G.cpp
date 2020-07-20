#include <bits/stdc++.h>
using namespace std;

bool vis[233333];

int main()
{
    int n, k, p = 1;
    cin >> n >> k;
    cout << p << " ";
    for (int i = 2; i <= n; i++)
    {
        if (!k)
            break;
        if (i % 2 == 0 && !vis[p + k])
        {
            printf("%d ", p + k);
            p += k;
            vis[p] = 1;
            k--;
        }
        else if (i % 2 && !vis[p - k])
        {
            printf("%d ", p - k);
            p -= k;
            vis[p] = 1;
            k--;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            printf("%d ", i);
    }
    return 0;
}