#include<iostream>
using namespace std;
int T;long long n,k;
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		cin>>n>>k;
		long long j=0;
		if(k%(n-1)==0)j=1;
		long long x=(k-j)/(n-1);
		long long y=x*n;
		k=(k-j)%(n-1);
		y+=k+j;
		cout<<y<<endl;
	}
	return 0;
}