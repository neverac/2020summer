#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX_N = 100088;

int A[2][MAX_N];
ll dp[MAX_N][4];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", A[i] + j);
        }
    }
    dp[0][0] = A[0][0];
    dp[0][1] = A[1][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][3]) + A[0][i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + A[1][i];
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][0]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][1]);
    }
    printf("%lld\n", *max_element(dp[n - 1], dp[n - 1] + 4));
    return 0;
}