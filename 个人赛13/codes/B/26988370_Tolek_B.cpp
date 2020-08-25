#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    double s = 1e100;
    for (int i = 1; i <= n; i++) {
        double x, y, z;
        scanf("%lf%lf%lf", &x, &y, &z);
        s = min(s, x * x + y * y + z * z);
    }
    printf("%.3lf", sqrt(s));
    return 0;
}