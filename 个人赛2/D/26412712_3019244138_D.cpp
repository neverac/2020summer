#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double Integral(double a, double b ,double c, double d, double e, double x){
    return (a/3)*x*x*x+(b-d)*x*x/2+(c-e)*x;
}
int main(){
    double x1, x2, x3, y1, y2, y3;
    int T ;
    cin  >> T;
    while(T--){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
        double a, b, c;
        double B, C;
        c=y1;
        b=x1;
        a=(y2-c)/((x2-b)*(x2-b));
        double d = (y3-y2)/(x3-x2);
        double e = y2-d*x2;
        B=-2*a*b;
        C=a*b*b+c;
        cout << setprecision(2) << fixed << Integral(a,B,C,d,e,x3)-Integral(a,B,C,d,e,x2)<< endl ; 
    }
    return 0;
}