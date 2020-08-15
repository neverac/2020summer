#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 505*505*2

using namespace std;

int r,s,p;
int rec[N];

int main()
{
	int i;
	int x,y;
	scanf("%d%d%d",&r,&s,&p);
	for(i=0;i<p;i++)
	{
		scanf("%d%d",&y,&x);
		if(x<=s)
			x=s+1-x;
		else
			x-=s;
		y=r+1-y;
		rec[i]=x+y;
	}
	sort(rec,rec+p);
/*	printf("----=-=-=--==\n");
	for(i=0;i<p;i++)
		printf("%d ",rec[i]);
	printf("\n----=-=-=--==\n");	*/
	for(i=1;i<p;i++)
		rec[i]=max(rec[i],rec[i-1]+1);
	printf("%d\n",rec[p-1]);
	return 0;
}