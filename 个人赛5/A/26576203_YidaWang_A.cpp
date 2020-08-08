#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long 
#define maxn 1000005
ll phi(ll x){
    ll res=x,tmp=x;
    for(ll i=2;i*i<=tmp;i++)
        if(tmp%i==0){
            res=res-res/i;
            while(tmp%i==0)
                tmp/=i;
        }
    if(tmp>1)
        res=res-res/tmp;
    return res;
}
ll Pow(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b%2)
            res=res*a%p;
        b>>=1;a=a*a%p;
    }
    return res;
}
ll f(ll n,ll p){
	if(p==1) return 0;
	if(n==1) return 1%p;
	else if (n==2) return 2%p;
	else if (n==3) return 9%p;
	else if (n==4) return Pow(4LL,9LL,p);
    ll t=phi(p);
//    printf("%lld  %lld\n",n,f(n-1,t));
	ll d = f(n-1,t)+t;
    return Pow(n,d,p);
}
int main(){
	ll N,P;
	cin>>N>>P;
	cout<<f(N,P)<<endl;
    return 0;

}