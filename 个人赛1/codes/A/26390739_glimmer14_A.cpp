#include <bits/stdc++.h>
using namespace std;

int val[10000];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> val[i];
    sort(val, val + n);
    int sum = 0;
    for (int i = 0; i < k; i ++)
        sum += val[i];
    cout << sum << endl;

}