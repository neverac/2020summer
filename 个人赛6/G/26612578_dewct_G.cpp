#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL a, b;
    cin >> a >> b;
    LL ans = 0;
    while (b)
    {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    cout << ans << endl;
    return 0;
}