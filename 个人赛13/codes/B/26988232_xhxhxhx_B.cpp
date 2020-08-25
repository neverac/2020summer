#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, y, z, ans = INT_MAX;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        ans = min(ans, x * x + y * y + z * z);
    }
    printf("%.3f\n", sqrt(ans));
    return 0;
}