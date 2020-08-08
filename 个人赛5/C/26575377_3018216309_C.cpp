#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400;
LL a[N];
int main() {
    int n;
    LL ans = 100;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int j = i + 1;
        while (j<=n&&a[j]>=a[j-1]) j++;
        j--;
        if (i==j) continue;
        ans += min(ans/a[i], 100000LL)*(a[j]-a[i]);
        i = j;
    }
    printf("%lld\n", ans);
    return 0;
}