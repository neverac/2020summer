#include <bits/stdc++.h>
using namespace std;

const int N =1e6+10;
double a,h,l;
double cnt(double x){
    return a/3*(x-h)*(x-h)*(x-h)+l*x;
}
int main(){
	int T;scanf("%d",&T);
    while(T--){
        double x[4],y[4];
        for(int i=1;i<=3;i++) scanf("%lf%lf",&x[i],&y[i]);
        h=x[1];
        l=y[1];
        a=(y[2]-l)/(x[2]-h)/(x[2]-h);
        //cout<<cnt(x[3])-cnt(x[2])-(y[2]+y[3])*(x[3]-x[2])/2<<endl;
        printf("%.2lf\n",cnt(x[3])-cnt(x[2])-(y[2]+y[3])*(x[3]-x[2])/2);
    }
    return 0;
}
