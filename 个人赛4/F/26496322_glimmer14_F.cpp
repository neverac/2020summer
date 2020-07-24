#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, s, p;
    cin >> k >> n >> s >> p;
    int tt = n / s + (n % s != 0);
    tt *= k;
    int ans = tt / p + (tt % p != 0);
    cout << ans << endl;
}