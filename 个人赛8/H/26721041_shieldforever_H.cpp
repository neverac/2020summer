#include<bits/stdc++.h>
using namespace std;
#define N 200020
int a[N], l[N], r[N], id[N], n;
void init(){
    cin>>n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    return ;
}
void solve(){
    l[0] = r[0] = 0;
    for(int i = 1; i <= n; ){
        int j = i + 1;
        while(a[j] > a[j - 1] && j <= n) ++j;
        l[++l[0]] = i; r[++r[0]] = j - 1;
        i = j;
    }
    int ans = r[1] - l[1] + 1;
    for(int i = 1; i < l[0]; i++){
        if(r[i] - l[i] == 0){
            ans = max(ans, r[i + 1] - l[i + 1] + 1); continue;
        }
        if(r[i + 1] - l[i + 1] == 0){
            ans = max(ans, r[i] - l[i] + 1); continue;
        }
        ans = max(ans, max(r[i + 1] - l[i + 1] + 1, r[i] - l[i] + 1));
        if(a[r[i] - 1] < a[l[i + 1]] || a[r[i]] < a[l[i + 1] + 1]){
            // cout<<a[r[i] - 1]<<' '<<a[l[i + 1]]<<' '<<a[r[i]] <<' '<< a[l[i + 1] + 1]<<endl;
            ans = max(ans, r[i + 1] - l[i]);
            // cout<<ans<<endl;
        }
    }
    printf("%d\n", ans);
    return ;
}
/*
5
4 1 2 3 2
*/
int main(){
    init();
    solve();
    return 0;
}