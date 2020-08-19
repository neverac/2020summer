#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int n;
long long int lis[200005];
long long ans;
int main()
{   cin>>n;
    for(long long int i=0;i<2*n;i++)
    {
        cin>>lis[i];
    }
    sort(lis,lis+2*n);
    ans=(lis[n-1]-lis[0])*(lis[2*n-1]-lis[n]);
    long long temp=lis[2*n-1]-lis[0];
    for(long long int i=1;i<n;i++)
    {
        ans=min(ans,temp*(lis[i+n-1]-lis[i]));
    }
    cout<<ans;
    return 0;
}
