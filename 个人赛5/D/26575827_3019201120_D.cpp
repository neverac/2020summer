#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
int t;

int main()
{
    ll n,k;
    cin>>t;
    while(t--)
    {
        ll ans;
        scanf("%lld%lld",&n,&k);
        ll p=k/(n-1);
        ll x=k%(n-1);
       
        if(x) ans=p*n+x;
        else ans=p*n-1;
        cout<<ans<<endl;
    }
   
    return 0;
}