#include<bits/stdc++.h>
using namespace std;
#define N 11
typedef long long LL;
LL a[N], n, m;

LL gcd(LL x, LL y){
    if(y == 0LL) return x;
    else return gcd(y, x % y);
}

void solve(){
    LL res = 0;
    for(LL i = 1; i < (1LL << m); i++){
        LL num = 0;
        for(LL j = i; j != 0; j >>= 1) num += j & 1;
        LL lcm = 1;
        for(LL j = 0; j < m; j++){
            if(i >> j & 1){
                lcm = lcm / gcd(lcm, a[j]) * a[j];
                if(lcm > n) break;
            }
        }
        if(num % 2 == 0) res -= n / lcm;
        else res += n / lcm;
    }
    printf("%lld\n", res);
    return ;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++) scanf("%lld", &a[i]);
    solve();
    return 0;
}