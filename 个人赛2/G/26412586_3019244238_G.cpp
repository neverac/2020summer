#include <stdio.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-k;i++)
		printf("%d ",i);
	int a=n,b=n-k+1;
	for(int i=2;i<=k;i=i+2)
		printf("%d %d ",a--,b++);
	if(k%2==1)
		printf("%d",a);
	puts("");
return 0;
}