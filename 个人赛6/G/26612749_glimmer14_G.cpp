#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while (b)
    {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    cout << ans << endl;
}