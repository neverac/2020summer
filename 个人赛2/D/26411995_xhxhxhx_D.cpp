#include <algorithm>
#include <cstdio>
using namespace std;

struct P
{
    double x;
    double y;
};

P p[3];

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        if (p[1].x > p[2].x)
            swap(p[1], p[2]);
        const double &x1 = p[0].x, &y1 = p[0].y, &x2 = p[1].x, &y2 = p[1].y, &x3 = p[2].x, &y3 = p[2].y;
        double D = (x1 - x2) * (x1 - x3) * (x2 - x3);
        double pa = (x1 * (y3 - y2) + x2 * (y1 - y3) + x3 * (y2 - y1)) / D;
        double pb = (x1 * x1 * (y2 - y3) + x2 * x2 * (y3 - y1) + x3 * x3 * (y1 - y2)) / D;
        double pc = (x2 * x3 * y1 * (x2 - x3) + x1 * x3 * y2 * (x3 - x1) + x1 * x2 * y3 * (x1 - x2)) / D;
        double k = (y3 - y2) / (x3 - x2);
        double la = k;
        double lb = -k * x2 + y2;
        double A = pa, B = pb - la, C = pc - lb;
        double ans = (1.0 / 3.0) * A * (x3 * x3 * x3 - x2 * x2 * x2) + 0.5 * B * (x3 * x3 - x2 * x2) + C * (x3 - x2);
        printf("%.2f\n", ans);
    }
    return 0;
}