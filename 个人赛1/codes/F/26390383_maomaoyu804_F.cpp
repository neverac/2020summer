#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;

int main(){
    ll n;scanf("%lld",&n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        ll num;
        scanf("%lld",&num);
        mp[num]++;
        sum+=num;
    }
    ll q;scanf("%lld",&q);
    for(ll i=0;i<q;i++){
        ll b,c;scanf("%lld%lld",&b,&c);
        mp[c]+=mp[b];
        sum+=mp[b]*(c-b);
        mp[b]=0;
        cout<<sum<<endl;
    }
    return 0;
}