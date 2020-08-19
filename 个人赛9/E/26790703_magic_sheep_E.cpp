#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

LL a,m;

LL gcd(LL x,LL y)
{
    if(x%y==0) return y;
    else return gcd(y,x%y);
}


LL phi(LL x){
    LL ans = x;
    for(LL i = 2; i*i <= x; i++){
        if(x % i == 0){
            ans = ans / i * (i-1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ans = ans / x * (x-1);
    return ans;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>m;
        cout<<phi(m/(gcd(a,m)))<<endl;
    }
    return 0;
}