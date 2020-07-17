#include <bits/stdc++.h>
using namespace std;

int num[233333];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num + 1, num + n + 1);
    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum += num[i];
    cout << sum;
    return 0;
}