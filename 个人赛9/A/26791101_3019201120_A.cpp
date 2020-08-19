#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//hope mm gl & hf
//hope TianJiang live longer

const int N=2e5+10;
ll a[N];

ll c[N];

ll ans1;

ll ans2;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n+n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+n);
    ll len=a[n+n-1]-a[0];
    ll k=a[n]-a[1];
    for(int i=1;i<n;i++)
    {
        c[i]=a[n+i-1]-a[i];
        if(c[i]<=k) k=c[i];
    }
    ans1=k*len;
    ans2=(a[n-1]-a[0])*(a[n+n-1]-a[n]);
    if(ans1<=ans2) cout<<ans1<<endl;
    else cout<<ans2<<endl;


    return 0;
}