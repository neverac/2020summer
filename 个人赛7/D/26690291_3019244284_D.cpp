#include <iostream>
#include<cstdio>
#define N 10010
using namespace std;
int n;
long long a[N];
long long res(long long x)
{
    while(x%2==0) 
	 x/=2;
    long long ret=1;
    for(int i=3;i<=7;i+=2)
	{
        long long tmp=1;
        long long sum=1;
        int num=0;
        while(x%i==0)
		{
            num++;
			x/=i;
            tmp*=i;
            sum+=tmp;
        }
        ret=ret*sum;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
	  scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) 
	  printf("%lld\n",res(a[i]));
    return 0;
}