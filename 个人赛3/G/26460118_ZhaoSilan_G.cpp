#include<stdio.h>
#include<iostream>
using namespace std;
const long long int mod = 998244353;
int n;
typedef long long int ll;
ll a[100005];
ll decc[30];
int len[20];
int Length(ll x)
{
    int len = 0;
    while (x)
    {
        len++;
        x /= 10;
    }
    return len;
}

int main()
{
    decc[0] = 1;
    for (int i = 1; i < 30; i++)//每一位的权重
    {
        decc[i] = decc[i - 1] * 10 % mod;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        len[Length(a[i])]++;
    }
    
    long long int ans = 0;
    int leng;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 1; j <= 10; j++)
        {
            ll sum = 0;
            ll x = a[i];
            int id=0;
            for (leng = j;x;x/= 10)
            {
                sum += decc[id]*(x % 10);
                if (leng)
                {
                    id++;
                    leng--;
                }
                id++;
            }
            
            x = a[i];
            id=0;
            for (leng=j;x;x/=10)
            {
                if (leng)
                {
                    id++;
                    leng--;
                }
                sum+=decc[id]*(x%10);
                id++;
            }
            ans=(ans+(sum%mod*len[j]) % mod)%mod;//有多少个会在这个位数上的
        }
    }
    printf("%lld", ans);
    return 0;
}
