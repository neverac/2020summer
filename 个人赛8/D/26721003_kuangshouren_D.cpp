#include<iostream>
using namespace std;
int n,T;
char s[107];
int a[107];
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		cin>>n;
		for(int i=1;i<=100;++i)s[i]='a';
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=max(1,a[1]);++i)cout<<s[i];
		cout<<endl;
		for(int i=2;i<=n+1;++i)
		{
			int l=max(a[i],a[i-1]);
			if(i==n+1)l=a[n];
			if(l==0)l=1;
			for(int j=a[i-1]+1;j<=l;++j)
			{
				if(s[j]!='z')s[j]=s[j]+1;
				else s[j]=s[j]-1;
			}
			for(int j=1;j<=l;++j)cout<<s[j];
			cout<<endl;
		}
	}
	return 0;
}