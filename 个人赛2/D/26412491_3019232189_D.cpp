#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int T;
double g[4][5],x[4],y[4];
double a,b,c,k1,k2;

void work(){
    double a1,a2,a3,b1,b2,b3,t1,t2;
    a1=g[1][1]-g[2][1];
    a2=g[1][2]-g[2][2];
    a3=g[1][4]-g[2][4];
    b1=g[1][1]-g[3][1];
    b2=g[1][2]-g[3][2];
    b3=g[1][4]-g[3][4];
    if(a1==0){
        b=a3/a2;
        a=(b3-b2*b)/b1;
    }
    else if(b1==0){
        b=b3/b2;
        a=(a3-a2*b)/a1;
    }
    else{
        a2/=a1;
        a3/=a1;
        b2/=b1;
        b3/=b1;
        a2-=b2;
        a3-=b3;
        b=a3/a2;
        a=b3-b*b2;
    }
    c=g[1][4]-g[1][1]*a-g[1][2]*b;


    k1=(y[3]-y[2])/(x[3]-x[2]);
    k2=y[3]-x[3]*k1;
    double l=x[2],r=x[3];
    if(l>r)
        swap(l,r);
    t1=( 1.0/3.0*a*r*r*r+1.0/2.0*b*r*r+c*r - 1.0/2.0*k1*r*r - k2*r );
    t2=( 1.0/3.0*a*l*l*l+1.0/2.0*b*l*l+c*l - 1.0/2.0*k1*l*l - k2*l );
    t1-=t2;
    printf("%.2f\n",abs(t1));
}

int main(){
    double t1,t2;
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=3;++i){
            scanf("%lf%lf",&t1,&t2);
            x[i]=t1;
            y[i]=t2;
            g[i][1]=t1*t1;
            g[i][2]=t1;
            g[i][3]=1;
            g[i][4]=t2;
        }
        work();
    }

    //while(1);
}
