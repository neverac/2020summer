#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;
const int N=100010;
int a[N];
int main()
{
    int n;
    cin>>n;
    int x;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum+=x;
        a[x]++;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int b,c;
        cin>>b>>c;
        sum+=(c-b)*a[b];
        a[c]+=a[b];
        a[b]=0;
        cout<<sum<<endl;
     }


    return 0;
}