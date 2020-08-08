#include<bits/stdc++.h>
using namespace std;
#define N 55

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(k <= n - 1){
            printf("%d\n", k);
        }
        else{
            k -= n - 1;
            long long a = k / (n - 1);
            long long ans = n + a * n;
            int b = k % (n - 1);
            if(b == 0) ans--;
            else{
                ans += b;
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}