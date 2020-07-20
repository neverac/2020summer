#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double x1, x2, x3, y1, y2, y3;
        scanf("%lf%lf", &x1, &y1);
        scanf("%lf%lf", &x2, &y2);
        scanf("%lf%lf", &x3, &y3);
        double a, b, c, k, b2;
        c = y1;
        b = x1;
        a = (y2 - c) / ((x2 - b) * (x2 - b));
        k = (y3 - y2) / (x3 - x2);
        b2 = y2 - k * x2;
        double ans1 = a * x3 * x3 * x3 / 3 - (2 * a * b + k) * x3 * x3 / 2 + (a * b * b + c - b2) * x3;
        double ans2 = a * x2 * x2 * x2 / 3 - (2 * a * b + k) * x2 * x2 / 2 + (a * b * b + c - b2) * x2;
        printf("%.2f\n", ans1 - ans2);
    }
    return 0;
}