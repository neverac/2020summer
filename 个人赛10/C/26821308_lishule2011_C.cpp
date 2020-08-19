
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int dp[maxn][26];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int len = s.size();
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 26; j++)
            dp[i][j] = dp[i - 1][j];
        dp[i][s[i - 1] - 'a']++;
    }
    int t;
    cin >> t;
    while (t--) {
        int l, r, sum = 0;
        cin >> l >> r;
        for (int i = 0; i < 26; i++)
            if (dp[r][i] - dp[l - 1][i])
                sum++;

        if (r == l || s[l - 1] != s[r - 1] || sum >= 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}