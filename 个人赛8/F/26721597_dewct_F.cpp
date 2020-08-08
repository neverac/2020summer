#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a;
        int len = a.length();
        int ans = len;
        for (int i = 0; i <= 9; i++)
        {
            int ls = 0;
            for (int j = 0; j < len; j++)
            {
                if (a[j] - '0' != i)
                    ls++;
            }
            ans = min(ans, ls);
        }
        // cout << ans << endl;
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                int ls = 0;
                for (int k = 0; k < len; k++)
                {
                    if (ls % 2 == 0 && a[k] - '0' == i)
                    {
                        ls++;
                    }
                    else if (ls % 2 == 1 && a[k] - '0' == j)
                        ls++;
                }
                // cout << ls << endl;
                if (ls % 2)
                    ls--;
                ans = min(ans, len - ls);
            }
        }
        cout << ans << endl;
    }
    return 0;
}