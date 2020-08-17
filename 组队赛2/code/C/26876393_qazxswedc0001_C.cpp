#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int n, op[100];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", op + i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int z = 1; z <= n; z++) {
                if (i == j || j == z || i == z) continue;
                if ((op[i] - op[j]) % op[z] || (op[j] - op[i]) % op[z]) {
                    printf("no");
                    return 0;
                }
            }
        }
    }
    printf("yes");
    return 0;
}