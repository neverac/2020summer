#include <bits/stdc++.h>
using namespace std;

struct qer
{
    int x, id;
    friend bool operator<(qer a, qer b)
    {
        return a.id > b.id;
    }
} num[233];

bool cmp(qer a, qer b)
{
    if (a.x == b.x)
        return a.id < b.id;
    return a.x > b.x;
}

priority_queue<qer> q;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i].x, num[i].id = i;
    sort(num + 1, num + n + 1, cmp);
    int t;
    cin >> t;
    while (t--)
    {
        while (!q.empty())
            q.pop();
        int k, pos;
        cin >> k >> pos;
        for (int i = 1; i <= k; i++)
            q.push(num[i]);
        int ans = 0;
        while (pos--)
            ans = q.top().x, q.pop();
        cout << ans << endl;
    }
    return 0;
}