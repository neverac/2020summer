#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005],b[100005];

int main(){
    ll aa,bb;scanf("%lld%lld",&aa,&bb);
    ll minn=1e8+5,maxx=0;
    ll ans=0;
    for(ll i=0;i<aa;i++){
        scanf("%lld",&a[i]);
        maxx=max(a[i],maxx);
        //ans+=(bb-1)*a[i];
    }
    for(ll i=0;i<bb;i++){
        scanf("%lld",&b[i]);
        minn=min(b[i],minn);
        //ans+=b[i];
    }
    sort(a,a+aa);
    sort(b,b+bb);
    for(int i=0;i<aa;i++) ans+=bb*a[i];
    //cout<<ans<<endl;
    if(maxx!=minn) ans+=b[0]-a[aa-2];
    for(int i=1;i<bb;i++){
        ans+=b[i]-a[aa-1];
    }
    if(minn<maxx) cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}