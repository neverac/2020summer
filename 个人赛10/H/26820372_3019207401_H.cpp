#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,ans,sum;
int lis[500];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>lis[i];
    }
    ans=500;
    for(int i=0;i<n;i++)
    {
        sum=lis[i];
        ans=min(ans,abs(360-2*sum));
        for(int j=i+1;j<n&&j!=i;j=(j+1)%n)
        {
            sum+=lis[j];
            ans=min(ans,abs(360-2*sum));
        }
    }
    cout<<ans<<endl;
    return 0;
}
