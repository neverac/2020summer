#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000050;
int vis[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int str[47];
    
    int a,b,c,s;
    while(cin>>a)
    {
    	if(a==0)
    	break;
    	cin>>b>>c>>s;
    	memset(vis,0,sizeof(vis));
    	int tmp=s;
    	int cnt=0;
    	while(tmp)
    	{
    		str[cnt++]=tmp%2;
    		tmp/=2;
		}
		for(int i=cnt;cnt<16;cnt++)
		{
			str[i++]=0;
		}
		tmp=s;
		while(!vis[tmp])
		{
			cnt=0;
			vis[tmp]=1;
			int tem=tmp;
			while(tem)
			{
				if(str[cnt]!=tem%2)
				{
					str[cnt]=3;
				}
				tem/=2;
				cnt++;
			}
			tmp=((a*tmp)+b)%c;
			
		}
		for(int i=15;i>=0;i--)
		{
			if(str[i]!=3)
			cout<<str[i];
			else
			cout<<"?";
		}
		cout<<endl;
	}
    return 0;
}
