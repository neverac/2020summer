#include <bits/stdc++.h>
using namespace std;
int n;
char op[100005];
int usm[500];
int main()
{
    scanf("%d", &n);
    scanf("%s", op + 1);
    for (int i = 1; i <= n; i++) {
        if (op[i] == '-')
            usm[i] = usm[i - 1] - 1;
        else
            usm[i] = usm[i - 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = min(ans, usm[i]);
    printf("%d", usm[n] - ans);
    return 0;
}