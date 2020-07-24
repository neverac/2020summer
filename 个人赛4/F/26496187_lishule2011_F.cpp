#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k,n,s,p;
    cin >> k >> n >> s >> p;
    long long ans = (k*((n-1)/s+1)-1)/p+1;
    cout << ans;
    return 0;
}
