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

ll T,n,k;

int main(){
    ll tt;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        tt=k/(n-1)*n+k%(n-1);
        if(tt%n==0)
            --tt;
        printf("%lld\n",tt);
    }

    //while(1);
}
