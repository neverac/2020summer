#include<iostream>
using namespace std;
int a[107],b[107];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	int i=1,j=1;
	while(i!=n+1&&j!=n+1)
	{
		if(a[i]>b[j])++j;
		else ++i;
	}
	cout<<n*2+2-i-j;
	return 0;
}