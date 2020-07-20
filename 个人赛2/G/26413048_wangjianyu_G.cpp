#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#define N 100100

using namespace std;


int main()
{
	int i,j,k,t,m,n;
	int l,r;
    int cnt ;
	while(~scanf("%d%d",&n,&k))
    {
		l = 1;
		r = n;
		if(k%2==0)
        {
			if(k==2)
			{
                printf("1 ");
				for(i=r;i>=2;i--)
					printf("%d ",i);
			}
			else
            {
				cnt = 0;
				int tp = (k%2==0)?k/2:(k-1)/2;
				for(;cnt<tp;l++,r--)
                {
                    printf("%d %d ",l,r);
					cnt++;
				}
				for(;l<=r;r--)
					printf("%d ",r);
			}
		}
		else
        {
			cnt = 0;
			if(k==1)
			{
				for(i=1;i<=n;i++)
                {
					printf("%d ",i);
				}
			}
			else
            {
				cnt =0;
				for(;cnt<(k-1)/2;l++,r--)
                {
					printf("%d %d ",l,r);
					cnt++;
				}
				for(;l<=r;l++){
					printf("%d ",l);
				}
			}
		}
		printf("\n");
	}
    return 0;
}
