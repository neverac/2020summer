#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve(ll n)
{
    ll x = 26;
    int cnt = 1;
    while (n > x)
    {
        n -= x;
        x = x * 26;
        cnt ++;
    }

    n -= 1;
    string ans = "";
    while (n)
    {
        ans = (char)('a' + (n % 26ll)) + ans;
        n /= 26;
    }
    // cout << ans << endl;
    // cout << (cnt - ans.length()) << endl;
    int len = cnt - ans.length();
    for (int i = 0; i < len; i ++)
        ans = 'a' + ans;
    return ans;
    
}

int main()
{
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    // n --;
    // if (n == 0)
    // {
    //     cout << 'a' << endl;
    //     return 0;
    // }
    // string ans;
    // while (n)
    // {

    //     ans = (char)('a' + (n % 26ll)) + ans;
    //     n /= 26;
    // }
    // cout << ans << endl;
    
}