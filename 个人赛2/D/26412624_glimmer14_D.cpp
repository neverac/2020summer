#include <iostream>
#include <cmath>
using namespace std;

double aa[3];
inline double solve(double x, int n)
{
    double ans = 0;
    for (int i = 0; i < n; i ++)
        ans += aa[i] / (i + 1) * pow(x, i + 1);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double x1, yy1, x2, y2, x3, y3;
        double a, b, c, e, f;
        cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3;

        c = yy1;
        b = x1;
        a = (y2 - c) / ((x2 - b) * (x2 - b));

        e = (y2 - y3) / (x2 - x3);
        f = y3 - e * x3;

        aa[0] = a * b * b + c - f;
        aa[1] = -(2 * a * b + e);
        aa[2] = a;
        double ans = solve(x3, 3) - solve(x2, 3);
        printf("%.2lf\n", ans);
    }
    return 0;
}
