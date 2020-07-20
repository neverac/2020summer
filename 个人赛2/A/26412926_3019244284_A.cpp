#include<iostream>
#include<cstring>
#define max(a,b) a>b?a:b
using namespace std;
int map[60][60];
int room[60][60];
int maxn,num=0,area;

void dfs(int i,int j)
{
	if(room[i][j])
	return ;
	area++;
	room[i][j]=num;
	if((map[i][j]&1)==0) dfs(i,j-1);
	if((map[i][j]&2)==0) dfs(i-1,j);
	if((map[i][j]&4)==0) dfs(i,j+1);
	if((map[i][j]&8)==0) dfs(i+1,j);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
    	num=0;
    	maxn=0;
    	memset(room,0,sizeof(room));
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cin>>map[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(!room[i][j])
				{
					area=0;
					num++;
					dfs(i,j);
					maxn=max(maxn,area);
				}
			}
		}
		cout<<num<<endl;
		cout<<maxn<<endl;
	}
    return 0;
}
