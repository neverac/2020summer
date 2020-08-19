#include <bits/stdc++.h>
using namespace std;

struct qer
{
    int a, b, x, id;
    friend bool operator<(qer A, qer B)
    {
        return A.x > B.x;
    }
} num[200050];

bool vis[2000500];

priority_queue<qer> q[4];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].x;
        num[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].b;
        if (num[i].a != num[i].b)
            q[num[i].a].push(num[i]);
        q[num[i].b].push(num[i]);
    }
    int T;
    cin >> T;
    while (T--)
    {
        int ls;
        cin >> ls;
        qer ans;
        if (!q[ls].empty())
            ans = q[ls].top(), q[ls].pop();
        else
        {
            cout << -1 << endl;
            continue;
        }
        while (vis[ans.id])
        {
            if (q[ls].empty())
            {
                ans.x = -1;
                break;
            }
            ans = q[ls].top();
            q[ls].pop();
        }
        vis[ans.id] = 1;
        cout << ans.x << endl;
    }
    return 0;
}