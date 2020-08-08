#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        long long ans = k/(n-1) * n + k%(n-1);
        if (k%(n-1) == 0) ans--;
        cout << ans << endl;
    }
}