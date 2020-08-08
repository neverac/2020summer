#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
int A[110], B[110];
int main()
{
    int N = readint();
    for (int i = 1; i <= N; i++)
    {
        A[i] = readint();
    }
    for (int i = 1; i <= N; i++)
    {
        B[i] = readint();
    }
    int l = 1, r = 1;
    while (l <= N && r <= N)
    {
        if (A[l] > B[r])
        {
            r++;
        }
        else
        {
            l++;
        }
    }
    int ans;
    if (l <= N)
    {
        ans = N - l + 1;
    }
    else
    {
        ans = N - r + 1;
    }
    printf("%d", ans);
    return 0;
}