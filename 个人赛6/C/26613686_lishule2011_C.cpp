//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//
//int main(){
//    ll a, b;
//    cin >> a >> b;
//    ll ans = 0;
//    if (a>=b){
//        ans+=a/b;
//        a=a%b;
//    }
//    if (a == 0) {
//        cout << ans;
//        return 0;
//    }
//    while (b>1){
//        ans+=b/a;
//        int t = b;
//        b=a;
//        a = t % b;
//    }
////    if (b==1 && a>0);ans+=b;
//    cout << ans;
//
//}













#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 100;
int father[maxn], n, k, a, b;

int getfather(int x) {
    return father[x] == x ? x : father[x] = getfather(father[x]);
}
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < maxn; i++) father[i] = i;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        if ((a = getfather(a)) == (b = getfather(b)))
            ans++;
        else
            father[b] = a;
    }
    cout << ans << endl;
    return 0;
}


