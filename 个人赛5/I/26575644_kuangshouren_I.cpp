#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[300007],b[300007];
char s[300007];
int n,T;
int main()
{
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		int tot1=0,tot2=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i)
		{
			int x=s[i]-'0';
			if(x%2==1)
			{
				++tot1;
				a[tot1]=x;
			}
			else
			{
				++tot2;
				b[tot2]=x;
			}
		}
		int i=1,j=1;
		for(int k=1;k<=n;++k)
		{
			if(i==tot1+1||(a[i]>b[j]&&j!=tot2+1))
			{
				printf("%d",b[j]);++j;
			}
			else
			{
				printf("%d",a[i]);++i;
			}
		}
		cout<<endl;
	}
	return 0;
}