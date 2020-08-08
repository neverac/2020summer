#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
const int INF = 1e9;
inline int readint(){
    int ret = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll(){
    ll ret = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
ll solve(ll n, ll mod){
    ll t = n / mod;
    ll l = n - t * mod;
    if(t == 0)
        return n;
    return t * mod + solve(l + t, mod);
}
int main(){
    int T = readint();
    while(T--){
        ll n = readll(), k = readll();
        printf("%lld\n", solve(k, n));
    }
    return 0;
}