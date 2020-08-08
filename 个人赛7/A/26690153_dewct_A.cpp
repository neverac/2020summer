#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string a;

int pos[30][100050];

int main()
{
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    cin >> a;
    int len = a.length();
    ll ans = 0;
    for (int i = 1; i <= 26; i++)
    {
        int lsk = 0;
        for (int j = 0; j < len; j++)
        {
            if (a[j] - 'a' + 1 == i)
                pos[i][++lsk] = j + 1;
            if (lsk <= k && lsk != 0)
                ans += pos[i][lsk];
            else if (lsk > k)
                ans += pos[i][lsk] - pos[i][lsk-k];
        }
    }
    cout << ans << endl;
    return 0;
}