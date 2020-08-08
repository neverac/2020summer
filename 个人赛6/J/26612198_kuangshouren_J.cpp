#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
long long ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
	int x;
	scanf("%d",&x);
	if(x!=0)
	ans+=(x-1)/k+1;
	}
	cout<<(ans+1)/2;
	return 0;
}