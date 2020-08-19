#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=0,zum=361;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			sum+=a[j];
			zum=min(zum,abs(360-2*sum));
			if(sum>180)
				break;		
		}
		sum=0;
	}	printf("%d\n",zum);
} 
