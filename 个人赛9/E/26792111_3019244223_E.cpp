#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define ll  long long
#define ull unsigned long long

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}

ll phi(ll x)
{
    ll res = x;
    for (ll i = 2; i*i<= x ; ++i)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main()
{  
    ll t;
    scanf("%I64d",&t);
    while(t--)
    {
        ll a,b;
        scanf("%I64d%I64d",&a,&b);
        ll d=gcd(a,b);
        cout<<phi(b/d)<<endl;

    }




    //system("pause");
    return 0;
}

