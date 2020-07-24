#include <iostream>

using namespace std;


int gcd(int x,int y) {
    return y? gcd(y,x%y):x;
}

int main() {
    int cnt=0;
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cnt++;
        int n, a, b;
        cin >> n >> a >> b;
        int g = gcd(a, b);
        n /= g;
        cout << "Case #" << (cnt) <<": ";
        if (n & 1) cout << "Yuwgna\n";
        else cout << "Iaka\n";
    }
}
