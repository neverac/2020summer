#include<iostream>
#include<cstdio>
#include<algorithm>
int a[100007],b[100007];
int n,m;
using namespace std;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(a[n]>b[1])
	{
		cout<<"-1";
		return 0;
	}
	long long sum1=0,sum2=0;
	for(int i=1;i<=n-1;++i)
	sum1+=a[i];
	for(int i=1;i<=m;++i)
	sum2+=b[i];
	if(a[n]==b[1])cout<<(sum1*m+sum2);
	else
	cout<<(sum1*m+sum2)+(a[n]-a[n-1]);
	return 0;
}