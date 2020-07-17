#include <bits/stdc++.h>
using namespace std;
long long op[100005];
int n;
long long sum = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        op[x] += x;
        sum += x;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        long long tmp = op[a] / a * b;
        sum += tmp - op[a];
        op[b] += op[a] / a * b;
        op[a] = 0;
        printf("%lld\n", sum);
    }
    return 0;
}