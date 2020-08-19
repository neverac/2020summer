#include <iostream>
#include <cmath>
using namespace std;
long long a,m;

long long gcd(long long a,long long b)
{
        long long t;
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        while(t=a%b)
        {
            a=b;
            b=t;
        }
        return b;
}

long long euler(long long n)
{
    long long t=n, sn=sqrt(n+1);
    for(long long i=2; i<=sn; ++i)
    {
        if(n%i==0)
        {
            t=t/i*(i-1);
            while(n%i==0) n/=i;
        }
        if(n==1) break;
    }
    if(n>1) t=t/n*(n-1);
    return t;
}

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        cin>>a>>m;
        long long g = gcd(a,m);
        m = m /g;
        long long ans = euler(m);
        cout<<ans<<endl;
    }
    return 0;
}
