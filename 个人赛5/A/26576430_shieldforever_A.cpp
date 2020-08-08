#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL quickpow(LL x, LL y, LL z)
{
    LL ans = 1;
    while(y)
    {
        if(y&1)
            ans = ans * x % z;
        x = x * x % z;
        y >>= 1;
    }
    return ans;
}

LL phi(LL n)
{
    LL i, rea = n;
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            rea = rea - rea / i;
            while(n % i == 0)
                n /= i;
         }
    }
    if(n > 1)
        rea = rea-rea/n;
    return rea;
}

LL solve(LL n, LL m){
    if(n == 2 && m > 1) return n % m;
    if(m == 1) return 0LL;
    return quickpow(n, solve(n - 1, phi(m)) + phi(m), m);
}

int main(){
    LL n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", solve(n, m));
    return 0;
}