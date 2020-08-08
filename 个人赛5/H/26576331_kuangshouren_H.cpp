#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
bool v[1107],c[1007];
int main()
{
for(int i=2;i<=1100;++i)
{
	if(v[i]==0)
	{
		for(int j=i*i;j<=1100;j+=i)
		v[j]=1;
	}
}
cin>>n;
int k=0;
for(int i=n;i<=1100;++i)
{
	if(v[i]==0)
	{
		k=i;break;
	}
}
cout<<k<<endl;
k-=n;
for(int i=1;i<=n-1;++i)
{
	cout<<i<<" "<<i+1<<endl;
}
cout<<n<<" 1"<<endl;

for(int i=1;i<=n;++i)
{
	if(k==0)break;
	if(c[i]==0)
	{
		--k;
		cout<<i<<" "<<i+2<<endl;
		c[i]=1;c[i+2]=1;
		if(k==0)break;
	}
}
return 0;
}