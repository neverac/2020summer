#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 2147483640;
    while (n--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ans = min(ans, x * x + y * y + z * z);
    }
    printf("%.3f", sqrt((double)ans));
    return 0;
}