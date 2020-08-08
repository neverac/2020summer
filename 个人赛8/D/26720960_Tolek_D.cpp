#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
vector<char> s[105];
int n, aa[105];
inline char get(int at, int x)
{
    if (s[x].size() - 1 < at) return 'a';
    if (s[x][at] == 'a') return 'b';
    return 'a';
}
inline void solve(int a, int b, int c)
{
    if (aa[b] == 0) {
        s[c].push_back(get(0, b));
        return;
    }
    for (int i = 0; i < aa[b] && i < s[b].size(); i++) s[c].push_back(s[b][i]);
    while (s[c].size() < aa[b]) {
        char e = get(s[c].size(), a);
        s[b].push_back(e);
        s[c].push_back(e);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", aa + i);
        for (int i = 1; i <= n + 1; i++) s[i].clear();
        for (int i = 1; i <= 100; i++) s[1].push_back('a');
        for (int i = 1; i <= n; i++) solve(i - 1, i, i + 1);
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 0; j < s[i].size(); j++) printf("%c", s[i][j]);
            printf("\n");
        }
    }
    return 0;
}