#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MAX_N = 200088;

int A[MAX_N], dp[MAX_N][2];

int main()
{
    int N;
    scanf("%d%d", &N, A + 1);
    A[0] = 1e9 + 1;
    dp[1][0] = 1;
    for (int i = 2; i <= N; i++)
    {
        scanf("%d", A + i);
        dp[i][0] = A[i] > A[i - 1] ? dp[i - 1][0] + 1 : 1;
        dp[i][1] = max((A[i] > A[i - 1] ? dp[i - 1][1] + 1 : 1), (A[i] > A[i - 2] ? dp[i - 2][0] + 1 : 1));
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    printf("%d\n", ans);
    return 0;
}