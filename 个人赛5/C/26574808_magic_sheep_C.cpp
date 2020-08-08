#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int maxn = 1e5+100;

int d;
LL a[maxn],res,cnt;

int main()
{
	scanf("%d",&d);
	for(int i=1;i<=d;i++) scanf("%lld",&a[i]);
		res = 100;
	for(int i=2;i<=d;i++)
	{
		if(a[i-1]<a[i])
		{
			cnt = res/(a[i-1]);
			//cout<<cnt<<endl;
			if(cnt>100000) cnt = 100000;
			res = res + cnt*(a[i]-a[i-1]);
		}
	}
  	printf("%lld\n", res);
	return 0;
}