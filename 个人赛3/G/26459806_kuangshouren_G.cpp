#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
int n;
long long a[100007][10],b[100007][10];
char s[20];
int len[100007],c[107],cc[107];
long long gao(int x,int l)
{
	long long sum=0;
	for(int i=1;i<=l-x;++i)
	{
		sum=(sum*10+s[i]-'0')%mod;
	}
	for(int i=l-x+1;i<=l;++i)
	{
		sum=(sum*100+s[i]-'0')%mod;
	}
	return sum;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		len[i]=l;
		++c[l];
		for(int j=0;j<=l-1;++j)
		{
		a[i][j]=gao(j,l);
		b[i][j]=(a[i][j]*10)%mod;
		}
	}
	for(int i=1;i<=10;++i)cc[i]=c[i]+cc[i-1];
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		//cout<<"<<<"<<i<<">>>"<<endl;
		for(int j=1;j<=len[i]-2;++j)
		{
			ans+=a[i][j]*c[j];
			ans%=mod;
			//cout<<"<"<<a[i][j]<<" "<<c[j]<<">"<<endl;
		}
		ans+=(n-cc[max(len[i]-2,0)])*a[i][len[i]-1];
		ans%=mod;
		//cout<<"<<"<<a[i][len[i]-1]<<" "<<n-cc[max(len[i]-2,0)]<<">"<<endl;
		for(int j=0;j<=len[i]-2;++j)
		{
			ans+=b[i][j]*c[j+1];
			ans%=mod;
			//cout<<"<"<<b[i][j]<<" "<<c[j+1]<<">"<<endl;
		}
		ans+=(n-cc[len[i]-1])*b[i][len[i]-1];
		//cout<<"<<"<<b[i][len[i]-1]<<" "<<n-cc[len[i]-1]<<">"<<endl;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}