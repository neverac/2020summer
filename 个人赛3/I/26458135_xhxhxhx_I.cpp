#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 128;

char ch[MAX_N];

int main()
{
    int n;
    scanf("%d \n%s", &n, ch);
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == '-')
        {
            --cnt;
        }
        else
        {
            ++cnt;
        }
        ans = std::min(ans, cnt);
    }
    cnt = -ans;
    ans = -ans;
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == '-')
        {
            --cnt;
        }
        else
        {
            ++cnt;
        }
    }
    printf("%d\n", cnt);

    return 0;
}