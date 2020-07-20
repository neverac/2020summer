#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double fx(double a,double b,double c,double aa,double bb,double x){
     double cc;
     cc=a*x*x*x/3+b*x*x/2+c*x-aa*x*x*0.5-bb*x;
     return cc;
}



int main()
{
   int t;
   double x1,y1,x2,y2,x3,y3,a,b,c,aa,bb;
   cin>>t;
   while(t--){
      cin>>x1>>y1>>x2>>y2>>x3>>y3;
      a=(y2-y1)/((x2-x1)*(x2-x1));
      b=(-2)*a*x1;
      c=y1+a*x1*x1;
      aa=(y3-y2)/(x3-x2);
      bb=y2-x2*aa;

      cout<<fixed<<setprecision(2)<<fx(a,b,c,aa,bb,x3)-fx(a,b,c,aa,bb,x2)<<endl;
   }
   return 0;
}
