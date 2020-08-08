#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int val[N];
int fi[N], la[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> val[i];
    
    val[0] = INT_MAX;
    for (int i = 1; i <= n; i ++)
        fi[i] = val[i] > val[i - 1] ? fi[i - 1] : i;
    
    val[n + 1] = 0;
    for (int i = n; i >= 1; i --)
        la[i] = val[i] < val[i + 1] ? la[i + 1] : i;

    int ans = 1;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, la[i] - fi[i] + 1);


    for (int i = 2; i < n; i ++)
        if (val[i + 1] > val[i - 1])
            ans = max(ans, la[i + 1] - fi[i - 1]);
        
    cout << ans << endl;

}