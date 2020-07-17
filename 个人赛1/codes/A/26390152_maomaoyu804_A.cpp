#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[10005];

int main(){
    ll n,k;scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++) scanf("%lld",&num[i]);
    ll sum=0;
    sort(num,num+n);
    for(ll i=0;i<k;i++) sum+=num[i];
    cout<<sum<<endl;
    return 0;
}