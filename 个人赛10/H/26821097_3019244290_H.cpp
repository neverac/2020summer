#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
   int a[400];
   int n;
   while(~scanf("%d",&n))
   {
      for(int i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      int m=360;
      for(int i=0;i<n;i++)
      {
           int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
 
            m=min(m,abs(360-2*sum));
        }
      }
      printf("%d\n",m);
   }
    return 0;
}