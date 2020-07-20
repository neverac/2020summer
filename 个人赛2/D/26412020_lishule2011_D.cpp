#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
double x,y,x2,x3,y2,y3,l,h,a,k,b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> x >> y >> x2 >> y2>> x3>> y3;
        l = y;
        h = x;
        a = (y2-y)/((x2-x)*(x2-x));
        k = (y3 - y2)/(x3 - x2);
        b = y2-k*x2;
        double ans1 = (a*x3*x3*x3/3)-(a*h+k/2)*x3*x3+(a*h*h+l-b)*x3;
        double ans2 = (a*x2*x2*x2/3)-(a*h+k/2)*x2*x2+(a*h*h+l-b)*x2;
        printf("%.2lf\n",ans1-ans2);
    }

}