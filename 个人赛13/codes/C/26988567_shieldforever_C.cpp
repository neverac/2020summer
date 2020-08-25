#include<bits/stdc++.h>
using namespace std;
#define N 1010
string s[N];
int a[N];
int n, m;
int main(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>s[i];
    }
    sort(s + 1, s + 1 + m);
    int tot = unique(s + 1, s + 1 + m) - s - 1;
    // cout<<tot<<endl;
    for(int i = 1; i <= tot; i++) a[i] = s[i].size() + 1;
    sort(a + 1, a + 1 + tot);
    ++n;
    int ans = 0, sum = 0;
    for(int i = 1; i <= tot; i++){
        sum += a[i];
        if(sum <= n) ++ans;
    }
    cout<<ans<<endl;
}