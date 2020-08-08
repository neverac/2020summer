#include <cstdio>
using namespace std;

int main()
{
    int n, k, w, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w);
        ans += (w + k - 1) / k;
    }
    printf("%d\n", (ans + 1) / 2);
    return 0;
}