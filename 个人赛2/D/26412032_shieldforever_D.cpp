#include<iostream>
#include<cstdio>
using namespace std;
double a, b, c;
double p, q;
double x1, x2, x3, y1, y2, y3;

void init(){
    scanf("%lf%lf", &x1, &y1);
    scanf("%lf%lf", &x2, &y2);
    scanf("%lf%lf", &x3, &y3);
    b = ((x2 * x2 - x3 * x3) * (y1 - y2) - (x1 * x1 - x2 * x2) * (y2 - y3)) / ((x2 * x2 - x3 * x3) * (x1 - x2) - (x1 * x1 - x2 * x2) * (x2 - x3));
    a = (y1 - y2 - b * (x1 - x2)) / (x1 * x1 - x2 * x2);
    c = y1 - a * x1 * x1 - b * x1;
    p = (y3 - y2) / (x3 - x2);
    q = (x3 * y2 - x2 * y3) / (x3 - x2);
    double ans = (a / 3.0 * x3 * x3 * x3) + ((b - p) / 2.0 * x3 * x3) + (c - q) * x3;
    ans -= (a / 3.0 * x2 * x2 * x2) + ((b - p) / 2.0 * x2 * x2) + (c - q) * x2;
    if(ans < 0.0) ans *= -1.0;
    printf("%.2lf\n", ans);
    return ;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        init();
    }
    return 0;
}