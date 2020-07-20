#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<iostream>
using namespace std;
int main(){
    int T;
    double x1,y1,x2,y2,x3,y3,a,b,c,k,l;
    //y = ax^2 + bx + c;
    //y = kx+l;
    scanf("%d",&T);
    while(T--){
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        k = (y3-y2)/(x3-x2);
        l = y3 - k*x3;
        a = (y2-y1)/((x2-x1)*(x2-x1));
        b = -2*a*x1;
        c = y1-a*x1*x1-b*x1;
        double ans = a*(x3*x3*x3-x2*x2*x2)/3.0 + (b-k)*(x3*x3-x2*x2)/2.0 + (c-l)*(x3-x2);
        cout << setprecision(2) << fixed << ans << endl;
    }
    return 0;
}