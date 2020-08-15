#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;

struct Node
{
	char str[105];
	int len;
}node[1050];

int main()
{
	int n,cmp1,cmp2;
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
	{
		getchar();
		scanf("%s",node[i].str);
		node[i].len=strlen(node[i].str);
	}
	for(int i=1;i<=n;++i)
	{
		int j=0,k=0;
		while(1)
		{
			cmp1=0,cmp2=0;
			if(isdigit(node[0].str[j]) && isdigit(node[i].str[k]))
			{
				while(j<node[0].len && isdigit(node[0].str[j]))
				{
					cmp1=cmp1*10+node[0].str[j]-'0';
					++j;
				}
				while(k<node[i].len && isdigit(node[i].str[k]))
				{
					cmp2=cmp2*10+node[i].str[k]-'0';
					++k;
				}
				if(cmp1<cmp2)
				{
					printf("+\n");
					break;
				}
				else if(cmp1>cmp2)
				{
					printf("-\n");
					break;
				}
				else
				{
					if(j>=node[0].len)
					{
						printf("+\n");
						break;
					}
					if(k>=node[i].len)
					{
						printf("-\n");
						break;
					}
				}
			}
			else if(!isdigit(node[0].str[j]) && !isdigit(node[i].str[k]) && node[0].str[j]==node[i].str[k])
			{
				++j,++k;
				if(j>=node[0].len)
				{
					printf("+\n");
					break;
				}
				if(k>=node[i].len)
				{
					printf("-\n");
					break;
				}
			}
			else
			{
				if(node[0].str[j]<node[i].str[k])
					printf("+\n");
				else
					printf("-\n");
				break;
			}
		}
	}
return 0;
}