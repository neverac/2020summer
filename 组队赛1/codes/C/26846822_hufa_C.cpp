#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int step[500050];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int r,s,p,x,y,ans=0;
	scanf("%d%d%d",&r,&s,&p);
	for(int i=0;i<p;++i)
	{
		scanf("%d%d",&x,&y);
		step[i]=r-x+1+abs(s-y);
		if(y<=s)
			++step[i];
	}
	sort(step,step+p,cmp);
	for(int i=0;i<p;++i)
		ans=max(ans,step[i]+i);
	printf("%d\n",ans);
return 0;
}