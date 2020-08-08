#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e6 + 10;
char s[N];
int ans[N];

inline bool isone(int i)
{
    return (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e');
}

inline bool istwo(int i)
{
    return (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o');
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s", s);
        int n = strlen(s);

        int cnt = 0;
        int i = 0;

        while (i <= n - 5)
        {
            if (isone(i)) ans[cnt++] = i + 1, i += 2;
            else if (istwo(i))
            {
                if (isone(i + 2)) ans[cnt++] = i + 2, i += 3;
                else ans[cnt++] = i + 1, i += 2;
            }
            else i ++;
        }

        while (i <= n - 3)
        {
            if (isone(i)) ans[cnt++] = i + 1, i += 2;
            else if (istwo(i)) ans[cnt++] = i + 1, i += 2;
            else i ++;
        }

        printf("%d\n", cnt);
        // if (cnt == 0)
        for (int j = 0; j < cnt; j ++)
            printf("%d ", ans[j] + 1);
        // printf("%d\n", ans[cnt - 1]);
        putchar('\n');
    }
    
}