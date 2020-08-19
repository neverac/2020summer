#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

long long Euler( long long n ){
    long long res = n;
    for( long long i =2 ;i*i<=n;i++){
        if( n %i == 0 ){
            n/=i;
            res = res - res/i;
        }
        while( n % i==0)
            n/=i;
    }
    if( n > 1 )
        res = res - res/n;
    return res;
}
ll gcd(){

}
int main(){
    ios:;ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        ll a,m;
        cin >> a>> m;
        m = m/gcd(a,m);
        ll ans = Euler(m);
        cout << ans << endl;
    }

}