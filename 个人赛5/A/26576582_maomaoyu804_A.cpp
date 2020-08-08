#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpow(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1ll){
            ans*=a;ans%=mod;
        }
        a*=a;a%=mod;
        b>>=1ll;
    }
    return ans%mod;
}

ll phi(ll x){
    ll ret=x;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0) ret-=ret/i;
        while(x%i==0) x/=i;
    }
    if(x>1) ret-=ret/x;
    return ret;
}

ll solve(ll n,ll m){
    if(m==1) return 0;
    if(n==1) return 1%m;
    if(n==2) return 2%m;
    if(n==3) return 9%m;
    if(n==4) return (1<<18)%m;
    ll mm=phi(m);
    ll res=solve(n-1,mm)+mm;
    return qpow(n,res,m)%m;
}

int main(){
    //int t;scanf("%d",&t);
    //while(t--){
        ll n,m;scanf("%lld%lld",&n,&m);
        printf("%lld\n",solve(n,m));
    //}
    return 0;
}