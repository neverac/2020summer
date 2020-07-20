#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    cin >>T;
    double x1,x2,x3,y1,y2,y3;
    while(T--){
        cin >>x1>>y1>>x2>>y2>>x3>>y3;
        double t1=x3-x1,t2=x3-x2,t3=x2-x1;
        double k1=(y2-y1)/(double(3)*pow(t3,2));
        double k2=(2*y1-y2-y3)/double(2);
        double k3=(y2-y1)/double(3);
        cout<<fixed<<setprecision(2)<<k1*pow(t1,3)+k2*t2-k3*t3<<endl;
    }
    return 0;
}
