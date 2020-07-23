#include <bits/stdc++.h>
using namespace std;

char a[233333];

int main()
{
    int n;
    cin >> n;
    scanf("%s", a+1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '+')
            ans++;
        if (a[i] == '-' && ans)
            ans--;
    }
    cout << ans;
    return 0;
}