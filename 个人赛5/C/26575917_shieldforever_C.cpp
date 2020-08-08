#include<bits/stdc++.h>
using namespace std;
#define N 400
typedef long long LL;

int a[N];
int n;

void solve(){
    int i, j;
    LL ans = 100;
    for(i = 1; i <= n;){
        j = i + 1;
        while(a[j] >= a[j - 1] && j <= n) ++j;
        if(j == i + 1) {
            i = j;
        }
        else{
            LL num = ans / a[i];
            if(num <= 100000) ans = num * (a[j - 1] - a[i]) + ans;
            else{
                ans = ans - 100000LL * a[i] + 100000LL * a[j - 1];
            }
            i = j;
        }
    }
    printf("%lld\n", ans);
    return ;    
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    solve();
    return 0;
}
