#include<iostream>
#include<cstring>
#include<queue>
#define maxn 1000
using namespace std;
struct nodes
{
	int i;
	int j;
	int deep;
	int num;
	bool used;
};
nodes node[maxn*maxn];
int n,m;
string s;
queue<nodes> q;
int dis[4][2]={1,0,-1,0,0,-1,0,1};
int ans;
void bfs()
{
	nodes now;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(now.i+dis[i][0]>=0&&now.i+dis[i][0]<n&&now.j+dis[i][1]>=0&&now.j+dis[i][1]<m)
			{
				int tmp=(now.i+dis[i][0])*m+(now.j+dis[i][1]);
				if(!node[tmp].used)
				{
					node[tmp].used=true;
					node[tmp].deep=now.deep+1;
					q.push(node[tmp]);
					if(node[tmp].num==1)
		     		{
				    	ans=node[tmp].deep;
				    	break;
			    	}
				}	
			}
		}
		if(ans)
		{
			break;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
		{
			int tmp=i*m+j;
			node[tmp].i=i;
			node[tmp].j=j;
			node[tmp].num=s[j]-'0';
			if(s[j]-'0'==2)
			{
				node[tmp].used=true;
				node[tmp].deep=1;
				q.push(node[tmp]);
			}
		}
	}
	bfs();
	cout<<ans<<endl;
	return 0;
}