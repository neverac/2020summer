#include<bits/stdc++.h>
using namespace std;
#define N 800
int a[N], n;
void init(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]); a[i + n] = a[i];
    }
}
void solve(){
    for(int i = 1; i <= n * 2; i++) a[i] = a[i - 1] + a[i];
    int ans = 360;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= i + n - 1; j++){
            int x = a[j] - a[i - 1];
            int y = 360 - x;
            int d = x > y ? x - y : y - x;
            ans = min(ans, d);
        }
    }
    printf("%d\n", ans);
    return ;
}
int main(){
    init();
    solve();
    return 0;
}