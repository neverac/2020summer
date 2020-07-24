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

ll k,n,s,p;

int main(){
    ll ans=0;
    scanf("%lld%lld%lld%lld",&k,&n,&s,&p);
    if(n>n/s*s)
        n=n/s+1;
    else
        n=n/s;
    ans=k*n;
    
    if(ans>ans/p*p)
        printf("%lld\n",ans/p+1);
    else
        printf("%lld\n",ans/p);
    

    //while(1);
}
