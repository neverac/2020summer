#include <bits/stdc++.h>
using namespace std;

string a[1050];
int num[1050];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + m + 1);
    m = unique(a + 1, a + m + 1) - a;
    m--;
    // for (int i = 1; i <= m; i++)
    //     cout << a[i] << endl;
    for (int i = 1; i <= m; i++)
    {
        num[i] = a[i].length();
    }
    sort(num + 1, num + m + 1);
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        if (n >= num[i])
            n -= num[i], tot++;
        else
            break;
        n--;
        // cout << n << endl;
    }
    cout << tot << endl;
    return 0;
}