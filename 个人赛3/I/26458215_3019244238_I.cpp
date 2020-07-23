#include <stdio.h>
#include <algorithm>
using namespace std;

char str[105];

int main()
{
	int n,ans=0,Min=0;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;++i)
	{
		if(str[i]=='-')
			--ans;
		else
			++ans;
		Min=min(Min,ans);
	}
	ans-=Min;
	printf("%d\n",ans);
return 0;
}