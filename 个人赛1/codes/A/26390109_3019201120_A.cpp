#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int N=1010;

int a[N];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<k;i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;






    return 0;
}