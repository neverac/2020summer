#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long LL;
LL a[N];
int n;
int main(){
    cin>>n;
    LL ans = 0LL;
    for(int i = 1; i <= n; i++){
        int j;
        scanf("%d", &j);
        a[j]++;
        ans += j;
    }
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++){
        LL b, c;
        scanf("%lld%lld", &b, &c);
        if(a[b] > 0){
            ans += (c - b) * a[b];
            a[c] += a[b]; a[b] = 0LL;
        }
        printf("%lld\n", ans);
    }

    return 0;
} 