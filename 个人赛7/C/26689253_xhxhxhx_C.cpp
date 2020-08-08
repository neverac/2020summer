#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 128;

int A[MAX_N], B[MAX_N];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", B + i);
    }
    int pa = 0, pb = 0;
    while (pa < N && pb < N)
    {
        if (A[pa] < B[pb])
        {
            ++pa;
        }
        else
        {
            ++pb;
        }
    }
    printf("%d\n", max(N - pa, N - pb));
    return 0;
}