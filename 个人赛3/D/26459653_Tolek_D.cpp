#include <bits/stdc++.h>
using namespace std;
int n, s1, s2, ss[400005];
vector<int> vec;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1)
            ++s1;
        else
            ++s2;
    }
    for (int i = 2; i <= 400000; i++) {
        if (ss[i]) continue;
        for (int j = 2; 1ll * i * j <= 400000; j++) ss[i * j] = 1;
    }
    for (int i = 2; i <= 400000; i++) {
        if (!ss[i]) vec.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        int x = vec[i] - ans;
        int p = min(x / 2, s2);
        for (int j = 1; j <= p; j++) printf("2 ");
        s2 -= p, x -= p * 2, ans += 2 * p;
        p = min(s1, x);
        for (int j = 1; j <= p; j++) printf("1 ");
        x -= p, s1 -= p, ans += p;
        if (s1 == 0 && s2 == 0) break;
    }
    if (s1 != 0 || s2 != 0) {
        while (s2) printf("2 "), --s2;
        while (s1) printf("1 "), --s1;
    }
    return 0;
}