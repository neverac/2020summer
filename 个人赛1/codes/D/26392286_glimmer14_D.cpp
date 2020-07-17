#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, h;
int font[N], lef[N], top[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i ++)
        cin >> font[i];
    for (int i = 0; i < n; i ++)
        cin >> lef[i];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> top[i][j];

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cout << (top[i][j] ? min(font[j], lef[i]) : 0) << " ";
        }
        cout << endl;
    }
}