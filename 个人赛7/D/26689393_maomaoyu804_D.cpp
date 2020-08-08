#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;scanf("%lld",&n);
    while(n--){
        ll a;scanf("%lld",&a);
        //while(a%2==0) a/=2;
        ll cnt1=3,cnt2=5,cnt3=7;
        while(a%3==0) a/=3,cnt1*=3;
        while(a%5==0) a/=5,cnt2*=5;
        while(a%7==0) a/=7,cnt3*=7;
        cnt1=(cnt1-1)/2;
        cnt2=(cnt2-1)/4;
        cnt3=(cnt3-1)/6;
        printf("%lld\n",cnt1*cnt2*cnt3);
    }
    return 0;
}