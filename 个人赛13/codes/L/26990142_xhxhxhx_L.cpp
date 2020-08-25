#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int t, c[10];
    scanf("%d", &t);
    while (t--)
    {
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", c + i);
            cnt += c[i];
        }
        int cnt2 = 0;
        for (int i = 1; i < 10; i++)
        {
            cnt2 += c[i];
        }
        if (cnt == 0)
        {
            printf("-1\n");
            continue;
        }
        if (cnt == 1)
        {
            int ans = -1;
            if (c[0])
            {
                ans = 0;
            }
            else if (c[4])
            {
                ans = 4;
            }
            else if (c[8])
            {
                ans = 8;
            }
            printf("%d\n", ans);
            continue;
        }
        else if (cnt == 2)
        {
            int ans = -1;
            for (int i = 96; i >= 0; i -= 4)
            {
                int a = i / 10, b = i % 10;
                if ((a == 0 && c[b]) || (a == b && c[a] >= 2) || (a != b && c[a] && c[b]))
                {
                    ans = i;
                    break;
                }
            }
            printf("%d\n", ans);
            continue;
        }
        if (cnt2 == 0)
        {
            printf("0\n");
            continue;
        }
        int minans = 100;
        for (int i = 0; i < 100; i += 4)
        {
            int a = i / 10, b = i % 10;
            if ((a == b && c[a] >= 2) || (a != b && c[a] && c[b]))
            {
                minans = min(minans, max(a, b) * 10 + min(a, b));
            }
        }
        if (minans == 100)
        {
            int ans = -1;
            for (int i = 96; i >= 0; i -= 4)
            {
                int a = i / 10, b = i % 10;
                if ((a == 0 && c[b]) || (a == b && c[a] >= 2) || (a != b && c[a] && c[b]))
                {
                    ans = i;
                    break;
                }
            }
            printf("%d\n", ans);
        }
        else
        {
            int a = minans / 10, b = minans % 10;
            --c[a];
            --c[b];
            if (a < b)
                swap(a, b);
            for (int i = 9; i >= 0; i--)
            {
                for (int j = c[i] - 1; j >= 0; j--)
                {
                    printf("%d", i);
                }
            }
            if (b)
                printf("%d\n", (a * 10 + b) % 4 == 0 ? a * 10 + b : b * 10 + a);
            else
            {
                if ((a * 10 + b) % 4 == 0)
                {
                    if (a)
                    {
                        printf("%d\n", a * 10 + b);
                    }
                    else
                    {
                        printf("00\n");
                    }
                }
                else
                {
                    printf("0%d\n", a);
                    for (;;)
                        ;
                }
            }
        }
    }
    return 0;
}