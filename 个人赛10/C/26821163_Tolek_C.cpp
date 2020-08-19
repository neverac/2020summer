#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
typedef long long ll;
char op[N];
int n, q, sum[26][N];
int main()
{
    scanf("%s%d", op + 1, &q), n = strlen(op + 1);
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + (op[j] == i + 'a');
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r || op[l] != op[r]) {
            printf("Yes\n");
        } else {
            int num = 0;
            for (int i = 0; i < 26; i++) num += sum[i][r] - sum[i][l - 1] > 0;
            if (num >= 3) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}