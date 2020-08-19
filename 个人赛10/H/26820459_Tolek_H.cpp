#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int n, a[N], sum[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int s1, s2;
            s1 = sum[i + j - 1] - sum[i - 1];
            s2 = sum[i + n - 1] - sum[i + j - 1];
            ans = min(ans, abs(s1 - s2));
        }
    }
    printf("%d", ans);
    return 0;
}