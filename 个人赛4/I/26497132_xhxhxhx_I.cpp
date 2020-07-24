#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;

const ull MOD = 99999959;
const ull B = 21701039;
const int MAX_N = 100008;

int overlap(const string &a, const string &b);

int main()
{
    cin.sync_with_stdio(false);
    string ans, cur;
    int n;
    cin >> n >> ans;
    for (int i = 1; i < n; i++)
    {
        cin >> cur;
        int cnt = overlap(ans, cur);
        ans.append(cur.begin() + cnt, cur.end());
    }
    cout << ans << '\n';
    return 0;
}

int overlap(const string &a, const string &b)
{
    int al = a.length(), bl = b.length();
    int ans = 0;
    ull ah = 0, bh = 0, t = 1;
    int mab = min(al, bl);
    for (int i = 1; i <= mab; i++)
    {
        ah = (ah + a[al - i] * t) % MOD;
        bh = (bh * B + b[i - 1]) % MOD;
        if (ah == bh)
        {
            ans = i;
        }
        t = t * B % MOD;
    }
    return ans;
}