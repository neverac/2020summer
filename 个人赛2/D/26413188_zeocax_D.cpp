#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define ll long long
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        double x, y;
        double x1, y1;
        double x2, y2;
        scanf("%lf%lf%lf%lf%lf%lf", &x, &y, &x1, &y1, &x2, &y2);
        double A = ((y2 - y) / (x2 - x) - (y1 - y) / (x1 - x)) / (x2 - x1);
        double B = (y1 - y) / (x1 - x) - A * (x1 + x);
        double C = y - A * x * x - B * x;
        double a = (y2 - y1) / (x2 - x1);
        double b = y1 - a * x1;
        double f1 = 1.0 / 3.0 * A * (x2 * x2 * x2 - x1 * x1 * x1) + 1.0 / 2.0 * B * (x2 * x2 - x1 * x1) + C * (x2 - x1);
        f1 = fabs(f1);
        double f2 = 1.0 / 2.0 * a * (x2 * x2 - x1 * x1) + b * (x2 - x1);
        f2 = fabs(f2);
        double ans = fabs(f1 - f2);
        printf("%.2f\n", ans);
    }
    return 0;
}