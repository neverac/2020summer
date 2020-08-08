#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
void solve(){
    while(n--){
        LL x;
        scanf("%lld", &x);
        while(x % 2 == 0) x /= 2LL;
        int a = 0, b = 0, c = 0;
        while(x % 3 == 0) x /= 3LL, ++a;
        while(x % 5 == 0) x /= 5LL, ++b;
        while(x % 7 == 0) x /= 7LL, ++c;
        LL ans = 0;
        LL t1 = 0, t2 = 0, t3 = 0;
        LL o = 1;
        for(int i = 0; i <= a; i++){
            t1 += o;
            o *= 3LL;
        }
        o = 1;
        for(int i = 0; i <= b; i++){
            t2 += o;
            o *= 5LL;
        }
        o = 1;
        for(int i = 0; i <= c; i++){
            t3 += o;
            o *= 7LL;
        }
        ans = t1 * t2 * t3;
        printf("%lld\n", ans);
    }
}
int main(){
    cin>>n;
    solve();
    return 0;
}