#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define LL long long

double a,b,c,k,d;

double xa,ya,xb,yb,xc,yc;

double calc(double x){

   return a*x*x*x/3-(2*a*b+k)*x*x/2+(a*b*b+c-d)*x;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        double xa,ya,xb,yb,xc,yc;
        scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
        c=ya;
        b=xa;
        a=(yb-c)/((xb-b)*(xb-b));
        k=(yc-yb)/(xc-xb);
        d=yb-k*xb;
        printf("%.2f\n",calc(xc)-calc(xb));
    }
    return 0;
}
