#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 10;
string s;

const int mod = 5;
int power(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i ++)
        ans = ans * a % mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    int len = s.length();
    int x = s[len - 1] - '0';
    if (len >= 2)
        x += (s[len - 2] - '0') * 10;
    int ans = 0;
    for (int i = 1; i <= 4; i ++)
        ans += power(i, x);
    cout << ans % mod << endl;
}