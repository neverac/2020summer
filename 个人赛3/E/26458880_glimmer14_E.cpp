#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
ll dp[2][N];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 2; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> dp[i][j];

    for (int i = 2; i <= n; i ++)
    {
        for (int p = 0; p < 2; p ++)
        {
            int pp = 1 - p;
            dp[p][i] += max(dp[pp][i - 1], dp[pp][i - 2]);
        }
    }    

    ll ans = max(dp[0][n], dp[1][n]);
    cout << ans << endl;
}