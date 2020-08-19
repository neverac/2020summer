#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 512;

int A[MAX_N], B[MAX_N];

int main()
{
    int n, ans = MAX_N;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", A + i);
        A[i] += A[i - 1];
        for (int j = 0; j <= i; j++)
        {
            ans = min(ans, abs(A[i] - A[j] - 180));
        }
    }
    printf("%d\n", ans * 2);
    return 0;
}