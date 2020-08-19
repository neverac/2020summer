#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

struct qer
{
    int x, y, z;
} num[2050];

bool vis[23333];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].x >> num[i].y >> num[i].z;
    }
    for (int i = 1; i <= n; i++)
    {
        int ls = inf, a = 0, b = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            int ls2 = abs(num[i].x - num[j].x) + abs(num[i].y - num[j].y) + abs(num[i].z - num[j].z);
            if (ls2 < ls && !vis[i] && !vis[j])
            {
                a = i, b = j;
                ls = ls2;
            }
        }
        if (a && b)
        {
            cout << a << " " << b << endl;
            vis[a] = 1, vis[b] = 1;
        }
    }
    return 0;
}