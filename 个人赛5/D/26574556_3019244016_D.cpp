#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a = k / (n - 1);
        int b = k % (n - 1);
        long long c = 1ll * a * n + b;
        if ( b== 0) c--;
        printf("%lld\n", c);
    }
}