#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], b[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    for (int i = 0; i < n; i ++)
        cin >> b[i];
    
    int p1 = 0, p2 = 0;
    while (p1 < n && p2 < n)
    {
        a[p1] < b[p2] ? p1 ++ : p2 ++;
    }

    int ans = n - p1 + n - p2;
    cout << ans << endl;
    
}