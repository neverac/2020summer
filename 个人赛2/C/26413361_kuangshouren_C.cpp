#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
char s[107];
long long suan(int x,int y)
{
	long long sum=0;
	for(int i=x;i<=y;++i)
	{
		sum=sum*10+(s[i]-'0');
	}
	return sum;
}
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		long long maxn=(long long)-0x3f3f3f3f3f3f3f3f;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=3;i<=n-2;++i)
		{
			long long a1=max(suan(1,1)+suan(2,i-1),suan(1,i-2)+suan(i-1,i-1));
			long long x=suan(i,i)*suan(i+1,i+1)/suan(i+2,n);
			maxn=max(maxn,a1-x);
		}
		cout<<"Case #"<<w<<": "<<maxn<<endl;
	}
	return 0;
}