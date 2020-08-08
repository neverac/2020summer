#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int m,n;
ll ans;
int a[105];
bool alive[105];
bool blive[105];
int b[105];
int leftpos;
int rightpos;
int main()
{   cin>>n;
    ans=2*n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    leftpos=1;
    rightpos=1;
    while(1)
    {
       if(a[leftpos]>b[rightpos])
       {
           rightpos++;
           ans--;

       }
       else
       {
           leftpos++;
           ans--;

       }
       if(leftpos==n+1||rightpos==n+1)
       {
        cout<<ans<<endl;
        return 0;
       }
    }

}
