#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int l = s.length();
    int ans ;
    if(l >= 2)
        ans = s[l - 1] - '0' + (s[l - 2] - '0') * 10;
    else
        ans = s[0] - '0';
    if(ans % 4 != 0) cout << "0";
        else cout << "4";
        

    return 0;
}
