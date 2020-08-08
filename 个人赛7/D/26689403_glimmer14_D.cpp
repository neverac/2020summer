#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int I = 34, J = 24, K = 20;
const ll MAX = 1e15 + 10;

ll dp[I][J][K];
ll func[3][I];

void init()
{
    func[0][0] = func[1][0] = func[2][0] = 1;
    for (int i = 1; i < I; i ++)
    {
        func[0][i] = func[0][i - 1] * 3;
        func[1][i] = func[1][i - 1] * 5;
        func[2][i] = func[2][i - 1] * 7;
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < I; i ++)
    {
        if (func[0][i] > MAX) break;
        for (int j = 0; j < J; j ++)
        {
            if (func[0][i] * func[1][j] > MAX) break;
            for (int k = 0; k < K; k ++)
            {
                if (func[0][i] * func[1][j] * func[2][k] > MAX) break;

                if (k)
                    dp[i][j][k] = dp[i][j][k - 1] + dp[i][j][0] * func[2][k];
                else if (j)
                    dp[i][j][0] = dp[i][j - 1][0] + dp[i][0][0] * func[1][j];
                else if (i)
                    dp[i][0][0] = dp[i - 1][0][0] + dp[0][0][0] * func[0][i];
            }
        }
            
    }
        
}

ll solve(ll x)
{
    int i = 0, j = 0, k = 0;
    while (x % 3 == 0)
        i ++, x /= 3;
    while (x % 5 == 0)
        j ++, x /= 5;
    while (x % 7 == 0)
        k ++, x /= 7;
    return dp[i][j][k];
}

int main()
{
    init();
    // for (int i = 0; i < 3; i ++)
    //     for (int j = 0; j < 3; j ++)
    //         for (int k = 0; k < 3; k ++)
    //             cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    int t;
    ll n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << solve(n) << endl;
    }
    
}