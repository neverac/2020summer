#include <bits/stdc++.h>
using namespace std;

int num[233333], ans[100050];
bool used[100050];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(used, 0, sizeof(used));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        ans[1] = num[1];
        int maxx = num[1];
        used[num[1]] = 1;
        int minn = 1;
        bool flag = 0;
        for (int i = 2; i <= n; i++)
        {
            if (num[i] > maxx)
            {
                maxx = num[i];
                ans[i] = num[i];
                used[num[i]] = 1;
            }
            else
            {
                while (used[minn] && maxx > minn)
                    minn++;
                if (used[minn])
                {
                    flag = 1;
                    break;
                }
                ans[i] = minn;
                used[minn] = 1;
            }
        }
        if (flag)
        {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", ans[i]);
        }
        puts("");
    }
    return 0;
}