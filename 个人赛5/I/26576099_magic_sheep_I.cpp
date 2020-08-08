#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int T;
char s[301000];
queue<int> Q1,Q2;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n = strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			int u = s[i]-'0';
			if(u&1) Q1.push(u);
			else Q2.push(u);
		}
		for(int i=1;i<=n;i++)
		{
			if(!Q1.empty()&&!Q2.empty())
			{
				if(Q1.front()<Q2.front())
				{
					printf("%d", Q1.front());
					Q1.pop();
				}
				else
				{
					printf("%d", Q2.front());
					Q2.pop();
				}
			}
			else if(!Q1.empty())
			{
				printf("%d", Q1.front());
				Q1.pop();
			}
			else if(!Q2.empty())
			{
				printf("%d", Q2.front());
				Q2.pop();
			}
		}
		puts("");
	}
	return 0;
}