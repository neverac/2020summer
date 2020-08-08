#include <bits/stdc++.h>
using namespace std;

int num[233333];

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    int d1 = k, d2 = k;
    int tot = 0;
    for (int i = n; i >= 1;)
    {
        d1 = k, d2 = k;
        num[i] -= k;
        if (num[i] > 0)
            num[i] -= k;
        else
        {
            i--;
            num[i] -= k;
        }
        if (num[i] <= 0)
            i--;
        tot++;
    }
    cout << tot << endl;
    return 0;
}
