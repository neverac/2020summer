#include<iostream>
#include<cstring>
using namespace std;
int a,b,c,s;
bool v[70007];
bool p[20][2];
int main()
{
	while(1)
	{
		memset(v,0,sizeof(v));
		memset(p,0,sizeof(p));
		cin>>a;
		if(a==0)break;
		cin>>b>>c>>s;
		while(v[s]==0)
		{
			v[s]=1;
			int x=s;
			for(int i=0;i<=15;++i)
			{
				p[i][x%2]=1;
				x/=2;
			}
			s=(a*s+b)%c;
		}
		for(int i=15;i>=0;--i)
		{
			if(p[i][0]==1&&p[i][1]==1)cout<<"?";
			if(p[i][0]==1&&p[i][1]==0)cout<<"0";
			if(p[i][0]==0&&p[i][1]==1)cout<<"1";
		}
		cout<<endl;
	}
}