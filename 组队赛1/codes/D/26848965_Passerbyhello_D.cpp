#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 4000 + 5;
const int inf = 0x3f3f3f3f;

int dp[maxn][maxn], fa[maxn][maxn];
char s[maxn], t[maxn];
int nexta[maxn][2], nextb[maxn][2];
int l1, l2;
vector<int> ans;

int dfs(int x, int y) {
    if (x == l1+1 && y == l2+1) return 0;
    if (dp[x][y]) return dp[x][y];
    int tmp1 = dfs(nexta[x][0], nextb[y][0]),
        tmp2 = dfs(nexta[x][1], nextb[y][1]);
    if (tmp1 <= tmp2) fa[x][y] = -1; else fa[x][y] = 1;
    return dp[x][y] = min(tmp1, tmp2)+1;
}

void Print(int x, int y) {
    if (x == l1+1 && y == l2+1) return;
    int res = fa[x][y] > 0;
    ans.push_back(res);
    Print(nexta[x][res], nextb[y][res]);
}

int main() {
    scanf("%s%s", s+1, t+1);
    l1 = strlen(s+1), l2 = strlen(t+1);

    nexta[l1+1][1] = nexta[l1+1][0] = l1+1;
    nextb[l2+1][1] = nextb[l2+1][0] = l2+1;
    for (int i = l1; i >= 0; i--) {
        nexta[i][1] = nexta[i+1][1];
        nexta[i][0] = nexta[i+1][0];
        if (s[i+1] == '1') nexta[i][1] = i+1;
        else nexta[i][0] = i+1;
    }

    for (int i = l2; i >= 0; i--) {
        nextb[i][1] = nextb[i+1][1];
        nextb[i][0] = nextb[i+1][0];
        if (t[i+1] == '1') nextb[i][1] = i+1;
        else nextb[i][0] = i+1;
    }

    dfs(0, 0);
    Print(0, 0);

    for(auto count :ans) printf("%d", count);
    puts("");
}