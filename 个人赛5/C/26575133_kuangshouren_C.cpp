#include<iostream>
using namespace std;
long long p[507],c[507];
int n;
long long m=100,num;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
	cin>>p[i];
	if(p[i]<p[i-1])c[i-1]=1;
	if(p[i]>p[i-1])c[i-1]=2;
	}
	c[n]=1;
	for(int i=1;i<=n;++i)
	{
		if(c[i]==2)
		{
			num+=m/(p[i]);
			m%=p[i];
			if(num>100000)
			{
				m+=(num-100000)*p[i];
				num=100000;
			}
		}
		if(c[i]==1)
		{
			m+=num*(p[i]);
			num=0;
		}
	}
	cout<<m;
	return 0;
}