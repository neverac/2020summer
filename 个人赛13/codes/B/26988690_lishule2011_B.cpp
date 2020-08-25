#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long ans = 0x3f3f3f3f;
    while (n--){
        long long  x,y,z;
        cin >> x >> y >> z;
        ans = min(x*x+y*y+z*z,ans);
    }
//    cout << ans << endl;
    double res = sqrt(ans);
    cout << fixed << setprecision(3)<<res;
}