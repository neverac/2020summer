#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MAX_N = 100088;

int A[2 * MAX_N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        scanf("%d", A + i);
    }
    sort(A, A + 2 * n);
    ll ans = ll(A[n - 1] - A[0]) * ll(A[2 * n - 1] - A[n]);
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, ll(A[2 * n - 1] - A[0]) * ll(A[i + n - 1] - A[i]));
    }
    printf("%lld\n", ans);
    return 0;
}