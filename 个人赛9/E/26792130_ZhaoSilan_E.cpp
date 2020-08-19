#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;
ll eular(ll n){
    ll ans = n;
    for(ll i=2; i<=sqrt(n); i++){
        if(n%i==0){
            ans = ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans = ans/n*(n-1);
    return ans;
}
ll gcd(ll x, ll y)
{
     if(y == 0) return x;
     if(x < y)      return gcd(y,x);
     else        return gcd(y, x%y);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long int x,y;
        scanf("%lld%lld",&x,&y);
        ll t1=y/gcd(x,y);
      //  ll t2=(x+y)/gcd(x,y);
        printf("%lld\n",eular(t1));
    }
    return 0;
}
