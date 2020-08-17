#include<bits/stdc++.h>
using namespace std;

void solve(){
    priority_queue<int> q;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x; scanf("%d", &x); q.push(-x);
    }
    int ans = 0;
    for(int i = 1; i <= n - 1; i++){
        int x = q.top(); q.pop(); int y = q.top(); q.pop();
        ans += -(x + y); q.push(x + y);
    }
    cout<<ans<<endl;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}