#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        ans += (x % k == 0 ? x / k : x / k + 1);
    }
    printf("%lld\n", ans % 2 == 0 ? ans / 2 : ans / 2 + 1);
    return 0;
}