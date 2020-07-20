#include <bits/stdc++.h>
using namespace std;

int a[10]={1,0,0,0,1,0,1,0,2,1};
string num;
int k;
double kline,dline,bpow,cpow,apow;
double jifen(double x){
    return apow*x*x*x/3-(2*apow*bpow+kline)*x*x/2+(apow*bpow*bpow+cpow-dline)*x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase;
    cin>>kase;
    while(kase--){
        double xp1,yp1,xp2,yp2,xp3,yp3;
        cin>>xp1>>yp1>>xp2>>yp2>>xp3>>yp3;
        kline=(yp3-yp2)/((xp3-xp2));
        dline=yp2-kline*xp2;
        bpow=xp1;
        cpow=yp1;
        apow=(yp2-cpow)/((xp2-bpow)*(xp2-bpow));
        printf("%0.2lf\n",jifen(xp3)-jifen(xp2));
    }
}
