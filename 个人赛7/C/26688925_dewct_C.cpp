#include <bits/stdc++.h>
using namespace std;

int a[2333], b[2333];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int i = 1, j = 1;
    while (i <= n && j <= n)
    {
        if (a[i] > b[j])
            j++;
        else
        {
            i++;
        }
    }
    cout << max(n - i + 1, n - j + 1) << endl;
    return 0;
}