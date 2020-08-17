#include <stdio.h>
using namespace std;

int main()
{
	int n,A[55];
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&A[i]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				if(i!=j && j!=k && i!=k)
				{
					if((A[i]-A[j])%A[k])
					{
						printf("no\n");
						return 0;
					}
				}
			}
		}
	}
	printf("yes\n");
return 0;
}