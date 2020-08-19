#include <bits/stdc++.h>
using namespace std;

int num[400];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    // sort(num + 1, num + n + 1);
    int ans = 360, j = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += num[i];
        ans = min(ans, abs(sum - (360 - sum)));
        while (sum >= 180)
            sum -= num[j], ans = min(ans, abs(sum - (360 - sum))), j++;
    }
    // cout << ans << endl;
    cout << ans << endl;
    return 0;
}