#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
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

int main(){
	ll n;scanf("%lld",&n);
	for(ll i=0;i<n;i++){
		ll a,b;scanf("%lld%lld",&a,&b);
		ll qwq=gcd(a,b);
		//a/=qwq,b/=qwq;
		printf("%lld\n",phi(b/qwq));
		//cout<<phi(b/qwq)<<endl;
	}
	return 0;
}