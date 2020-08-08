#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;

long long n,k,l,r,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		if(k%(n-1))
		{
			ans=k/(n-1)+k;
			printf("%lld\n",ans);
		}
		else
		{
			ans=k/(n-1)*n-1;
			printf("%lld\n",ans);
		}
	}
	return 0;
}