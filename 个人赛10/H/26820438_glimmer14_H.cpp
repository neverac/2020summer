#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int sum[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> sum[i], sum[i + n] = sum[i];
    for (int i = 1; i <= 2 * n; i ++)
        sum[i] += sum[i - 1];
    
    int ans = 1000;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= i + n; j ++)
            ans = min(ans, abs((sum[j] - sum[i]) - (sum[i + n] - sum[j])));
    cout << ans << endl;
}