#include <stdio.h>
using namespace std;

long long a,m,d,ANS;

long long gcd(long long a,long long b)
{
	return a%b==0?b:gcd(b,a%b);
}

long long eular(long long n)
{
    long long ans=n;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
		ans=ans/n*(n-1);
    return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&m);
		d=gcd(a,m);
		ANS=eular(m/d);
		printf("%lld\n",ANS);
	}
return 0;
}