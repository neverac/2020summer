#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
typedef long long ll;
struct Node
{
    int x, y;
    Node(int a, int b)
        : x(a), y(b) {}
};
queue<Node> que;
int vis[N][N], n, m;
char op[N][N];
const int X[] = {0, 1, 0, -1}, Y[] = {1, 0, -1, 0};
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", op[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (op[i][j] == '1') que.push(Node(i, j)), vis[i][j] = 1;
        }
    }
    while (!que.empty()) {
        Node f = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = f.x + X[i], y = f.y + Y[i];
            if (x < 0 || x > n || y < 0 || y > m || vis[x][y]) continue;
            vis[x][y] = vis[f.x][f.y] + 1;
            que.push(Node(x, y));
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (op[i][j] == '2') ans = min(ans, vis[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}