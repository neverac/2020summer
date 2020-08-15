#include <bits/stdc++.h>
using namespace std;

string s[2];
int items[2][100];

inline int getItem(int x)
{
    int len = 0;
    int n = s[x].length();
    for (int i = 0; i < n; i ++)
    {
        if (isalpha(s[x][i]))
            items[x][len++] = s[x][i];
        else
        {
            int tt = 0;
            while (i < n && !isalpha(s[x][i]))
            {
                tt = tt * 10 + s[x][i] - '0';
                i ++;
            }
            items[x][len++] = -tt;
            i--;
        }
        // cout << items[x][len - 1] << " ";
    }
    // cout << endl;
    return len;
}

bool solve()
{
    int l1 = getItem(0);
    int l2 = getItem(1);
    int len = min(l1, l2);
    for (int i = 0; i < len; i ++)
    {
        if (items[0][i] == items[1][i])
            continue;
        if (items[0][i] < 0 && items[1][i] < 0)
            return -items[0][i] < -items[1][i];
        else  
            return items[0][i] < items[1][i];
    }
    return l1 <= l2;
}

int main()
{
    int n;
    cin >> n;
    cin >> s[0];
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[1];
        cout << (solve() ? "+" : "-") << endl;
    }
}