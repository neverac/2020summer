#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        long long n, m, x, y;
        scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
        if(x <= y) printf("%lld\n", m);
        else {
            long long ans = (n + (m - 1) * y) / x;
            printf("%lld\n", min(ans, m));
        }
    }
    return 0;
}