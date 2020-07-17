#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

bool vis[N];
int q[N], p[N];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, mi = 1;
        cin >> n;
        bool flag = true;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++)
        {
            cin >> q[i];
            if (q[i] < i)
            {
                flag = false;
            }
            if (flag)
            {
                if (q[i] != q[i - 1])
                {
                    p[i] = q[i];
                    vis[q[i]] = true;
                }
                else
                {
                    while (vis[mi])
                    {
                        mi ++;
                    }
                    p[i] = mi;
                    mi ++;
                }
            }
        }
        if (flag)
        {
            for (int i = 1; i <= n; i ++)
                cout << p[i] << " ";
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }
}