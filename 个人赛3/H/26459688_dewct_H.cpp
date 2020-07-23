#include <bits/stdc++.h>
using namespace std;

char mm[100][100];
int h[100], l[100];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, tot = 0;
        memset(h, 0, sizeof(h));
        memset(l, 0, sizeof(l));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> mm[i][j];
                if (mm[i][j] == 'A')
                    h[i]++, l[j]++, tot++;
            }
        if (tot == n * m)
            cout << 0 << endl;
        else if (tot == 0)
            cout << "MORTAL" << endl;
        else if (h[1] == m || h[n] == m || l[1] == n || l[m] == n)
        {
            cout << 1 << endl;
        }
        else
        {
            bool flag = 0;
            for (int i = 2; i < n; i++)
                if (h[i] == m)
                {
                    flag = 1;
                }
            for (int j = 2; j < m; j++)
                if (l[j] == n)
                    flag = 1;
            if (mm[1][1] == 'A' || mm[1][m] == 'A' || mm[n][1] == 'A' || mm[n][m] == 'A')
                flag = 1;
            if (flag)
                cout << 2 << endl;
            else
            {
                if (h[1] || h[n] || l[1] || l[m])
                    cout << 3 << endl;
                else
                {
                    cout << 4 << endl;
                }
            }
        }
    }
    return 0;
}