#include<iostream>
using namespace std;
int n,k;
int main()
{
	cin>>n>>k;
	int h=k+1;
	for(int i=n;i>=h+1;--i)printf("%d ",i);
	n=k+1;
	int ii=n,jj=1;
	while(ii>jj)
	{
		printf("%d ",ii);--ii;
		if(ii!=jj)
		printf("%d ",jj);++jj;
	}
	cout<<ii;
	return 0;
}