#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool check(long long int p,int a,int b,int x,int y) {
    int px = p / x; int py = p / y; int pxy = p/(x*y);
    long long int q = (p - px - py + pxy);
    int c1 = max(0, (int)(a - py +pxy));
    int c2 = max(0, (int)(b - px+ pxy));
    return (q >= c1 + c2);
}
int main() {
    long long int ans, res, l, r,mid;
    int a, b, x, y;
    while (scanf("%d%d%d%d", &a, &b, &x, &y) ==4) {
        l = 1; r = 1e16;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid,a,b,x,y)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}