#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        cout << (x<=y?m:min((n+(m-1)*y)/x,m)) <<endl;
    }
}