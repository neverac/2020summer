#include <bits/stdc++.h>

using namespace std;
int dev(int a,int b){
    return (a / b) + (a % b ? 1 : 0);
}
int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    double k, n, s, p;
    cin >> k >> n >> s >> p;
//    cout << dev(n, s);
//    cout<<3/2+3%2?1:0;
    cout << (dev(dev(n, s) * k, p)) << endl;
    return 0;
}
