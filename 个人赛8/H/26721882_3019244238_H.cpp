#include <stdio.h>
#include <algorithm>
using namespace std;

int a[200050],pos[200050],num=0;

int main()
{
	int n,Max=0;
	scanf("%d",&n);
	a[0]=0;
	pos[num++]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]<=a[i-1])
			pos[num++]=i;
	}
	pos[num++]=n+1;
	for(int i=0;i<num-1;++i)
		Max=max(Max,pos[i+1]-pos[i]);
	for(int i=0;i<num-2;++i)
		if(a[pos[i+1]-2]<a[pos[i+1]] || a[pos[i+1]-1]<a[pos[i+1]+1])
			Max=max(Max,pos[i+2]-pos[i]-1);
	printf("%d\n",Max);
return 0;
}