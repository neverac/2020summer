#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    // cout << max('a', 'A') << endl;
    cin >> t;
    cin >> a;
    int alen = a.length();
    for (int i = 0; i < t; i++)
    {
        b = "";
        cin >> b;
        int blen = b.length();
        int len = min(blen, alen);
        int flag = 0;
        for (int j = 0; j < len; j++)
        {
            if (a[j] >= '0' && a[j] <= '9' && b[j] >= '0' && b[j] <= '9')
            {
                int k1 = j, k2 = j;
                int an = a[j] - '0', bn = b[j] - '0';
                while (a[k1 + 1] >= '0' && a[k1 + 1] <= '9' && k1 + 1 < alen)
                    an = an * 10 + a[k1 + 1] - '0', k1++;
                while (b[k2 + 1] >= '0' && b[k2 + 1] <= '9' && k2 + 1 < blen)
                    bn = bn * 10 + b[k2 + 1] - '0', k2++;
                if (an > bn)
                {
                    flag = -1;
                    break;
                }
                else if (an < bn)
                {
                    flag = 1;
                    break;
                }
                j = k1;
            }
            else
            {
                if (a[j] > b[j])
                {
                    flag = -1;
                    // cout << 233 << endl;
                    break;
                }
                else if (a[j] < b[j])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag != 0)
        {
            if (flag == 1)
                cout << '+' << endl;
            else
                cout << '-' << endl;
        }
        else
        {
            if (alen <= blen)
                cout << '+' << endl;
            else
                cout << '-' << endl;
        }
    }
    return 0;
}