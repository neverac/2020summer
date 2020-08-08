#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	long long x,y,g,s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if(x>y) printf("%lld\n",y);
		else
		{
			s=y+y/(x-1);
			if(y%(x-1)==0)
			s--;
			printf("%lld\n",s);
		}
	}
}