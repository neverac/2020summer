#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double x1,y1,x2,y2,x3,y3;
    cin>>n;
    while(n--){
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        double a = (y2-y1)/((x2-x1)*(x2-x1));
        double k = (y2-y3)/(x2-x3);
        double b = y2 - k*x2;
        if(a < 0){
            double res = a/3*(x3*x3*x3 - x2*x2*x2)-(2*a*x1+k)/2*(x3*x3-x2*x2)+(a*x1*x1+y1-b)*(x3-x2);
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<res<<endl;
        }else{
            double res = -a/3*(x3*x3*x3 - x2*x2*x2)+(2*a*x1+k)/2*(x3*x3-x2*x2)+(b-a*x1*x1-y1)*(x3-x2);
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<res<<endl;
        }
    }
    return 0;
}
