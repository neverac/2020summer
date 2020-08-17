#include <bits/stdc++.h>
using namespace std;

int a[233];

int main()
{
    int n;
    int flag = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i == j || j == k || i == k)
                    continue;
                if ((a[i] - a[j]) % a[k] == 0)
                {
                    flag = 1;
                }
                else
                {
                    puts("no");
                    return 0;
                }
            }
        }
    }
    if (flag)
        puts("yes");
    return 0;
}
//233