#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
const int INF = 1 << 24;
const int MAX_N = 1024;

struct P
{
    int x;
    int y;
    int d;
    P()
    {
    }
    P(int x, int y, int d) : x(x), y(y), d(d)
    {
    }
    bool operator<(const P &ri) const
    {
        return d > ri.d;
    }
};

int dist[MAX_N][MAX_N];
char A[MAX_N][MAX_N];

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf(" \n%s", A[i] + 1);
        fill(dist[i] + 1, dist[i] + M + 1, INF);
    }
    queue<P> que;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i][j] == '1')
            {
                que.push(P(i, j, 1));
                dist[i][j] = 1;
            }
        }
    }
    while (!que.empty())
    {
        const P cur = que.front();
        que.pop();
        if (A[cur.x][cur.y] == '2')
        {
            printf("%d\n", cur.d);
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            const P nxt(cur.x + dx[i], cur.y + dy[i], cur.d + 1);
            if (A[nxt.x][nxt.y] && nxt.d < dist[nxt.x][nxt.y])
            {
                dist[nxt.x][nxt.y] = nxt.d;
                que.push(nxt);
            }
        }
    }
    return 0;
}