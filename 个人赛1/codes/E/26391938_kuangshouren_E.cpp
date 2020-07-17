#include<iostream>
using namespace std;
int a[1007],c[1007];
long long b[1007];
long long aaa=(long long)1000000000000001;
int h=0;
int main()
{
	long long n;
	scanf("%lld",&n);
	b[1]=26;
	int h=0;
	for(int i=1;;++i)
	{
		b[i]=(b[i-1]+1)*26;
		if(b[i]>aaa||b[i]<=0)
		{
			h=i;break;
		}
	}
	b[h+1]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=h;++i)
	{
		c[i]=n%26;
		n=(n-1)/26;
		if(n==0)
		{
			for(int j=i;j>=1;--j)
			{
				if(c[j]==0)cout<<"z";
				else
				cout<<(char)(c[j]+'a'-1);
			}
			break;
		}
	}
return 0;
}