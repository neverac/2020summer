#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        // ++k;
        long long s = k / (n - 1);
        if (k % (n - 1) == 0)
            printf("%lld\n", s * n - 1);
        else
            printf("%lld\n", s * n + k % (n - 1));
    }
    return 0;
}