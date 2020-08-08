#include<stdio.h>
#include<iostream>
using namespace std;
int a[105],b[105];
int main()
{
    int n;
    scanf("%d",&n);
//    int maxa=0;
//    int maxx=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
//        if(a[i]>maxa)
//        {
//            maxx=i;
//            maxa=a[i];
//        }
    }
    int maxb=0;
    int maxy=-1;
    for(int i=1;i<=n;i++)
      {
          scanf("%d",&b[i]);
//          if(b[i]>maxb)
//          {
//              maxb=b[i];
//              maxy=i;
//          }
      }
    int i=1,j=1;
    while(i<=n&&j<=n)
    {
        if(a[i]>b[j])
            j++;
        else
            i++;
    }
    
    if(i<=n)
        printf("%d\n",n-i+1);
   else
       printf("%d\n",n-j+1);
//    if(maxa>maxb)
//    {
//        printf("%d\n",n-maxx+1);
//    }
//    else
//    {
//        printf("%d\n",n-maxy+1);
//    }
    return 0;
}
