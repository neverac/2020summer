#include <bits/stdc++.h>
using namespace std;
long long bin[30], ps;
int main()
{
    long long s;
    bin[0] = 1;
    for (int i = 1; i < 30; i++) bin[i] = bin[i - 1] * 26;
    bin[0] = 1;
    scanf("%lld", &s);
    ps = s;
    int len;
    for (int i = 1; i < 30; i++) {
        if (s <= bin[i]) {
            len = i;
            break;
        } else
            s -= bin[i];
    }
    long long ys = 0;
    for (int i = len; i >= 1; i--) {
        if (i > 1) {
            printf("%c", (s % bin[i - 1] == 0 ? s / bin[i - 1] - 1 : s / bin[i - 1]) + 'a');
        } else {
            printf("%c", s + 'a' - 1), ys += s * bin[i - 1];
        }
        s -= (s % bin[i - 1] == 0 ? s / bin[i - 1] - 1 : s / bin[i - 1]) * bin[i - 1];
    }
    // printf("\n%d", ys == ps);
    return 0;
}