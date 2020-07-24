#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) {
    if (b == 0) return a;
    else return(gcd(b, a % b));
}

int main()
{
    int t, n, a, b;
    int k = 1;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        cout << "Case #" << k<< ": ";
        k++;
        if (n / gcd(a, b) % 2 == 1) cout << "Yuwgna" << endl;
        else cout << "Iaka" << endl;
    }
    return 0;
}