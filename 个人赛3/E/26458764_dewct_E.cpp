#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int h1[100050], h2[100050];
LL dp[2][100050];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h1[i];
    for (int i = 1; i <= n; i++)
        cin >> h2[i];
    dp[0][1] = h1[1];
    dp[1][1] = h2[1];
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + h1[i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + h2[i]);
    }
    cout << max(dp[0][n], dp[1][n]);
    return 0;
}