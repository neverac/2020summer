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

int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

int T;
int n,a,b;

int main(){
    int temp;
    scanf("%d",&T);
    for(int l=1;l<=T;++l){
        scanf("%d%d%d",&n,&a,&b);
        temp=gcd(a,b);
        n/=temp;
        if(n&1)
            printf("Case #%d: Yuwgna\n",l);
        else
            printf("Case #%d: Iaka\n",l);
    }


   // while(1);
}
