#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define N 110000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
//ll mod = 12;
using namespace std;

ll gcd(ll a,ll b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll a,m,x,k1,k2;
vector<ll> yinzi;
ll count_prime(ll x,ll n){
    yinzi.clear();
    ll i,j;
    for (i = 2; i * i <= n; i++)
        if(n%i==0){
            yinzi.push_back(i);
            while(n%i==0)
                n /= i;
        }
    if(n>1)
        yinzi.push_back(n);
    ll sum=0,value,cnt;
    for (i = 1; i < (1 << yinzi.size()); i++)
    {
        value=1;
        cnt=0;
        for (j = 0; j < yinzi.size(); j++)
        {
            if(i&(1<<j)){
                value*=yinzi[j];
                cnt++;
            }
        }
        if(cnt&1)
            sum+=x/value;
        else sum-=x/value;
    }
    return x-sum;
}
int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%lld %lld", &a, &m);
        x=gcd(a,m);
        k1=a/x;k2=m/x;
        printf("%lld\n", count_prime(k2 + k1 - 1, k2) - count_prime(k1 - 1, k2));
    }
    return 0;
}
