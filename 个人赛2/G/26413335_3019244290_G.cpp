#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
        for(int i=1;i<=n-k;i++)
        {
            printf("%d ",i);
        }
        int x=n-k+1;
        while(x<=n)
        {
            printf("%d ",n--);
            if(x<=n)
                printf("%d ",x++);
            else
                break;
        }
        printf("\n");
    return 0;
}