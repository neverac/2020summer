#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 128;

int ans[MAX_N][MAX_N], A[MAX_N], B[MAX_N];

int main()
{
    int m, n, h;
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", A + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", B + i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", ans[i] + j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j])
            {
                ans[i][j] = min(A[j], B[i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", ans[i][j], j + 1 == m ? '\n' : ' ');
        }
    }

    return 0;
}
