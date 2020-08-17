#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		long long ans;
		scanf("%lld",&n);
		ans=((n+1)*n)^(n+1);
		printf("%lld\n",ans);
	}
	return 0;
}