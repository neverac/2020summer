#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node
{
    int val;
    Node* p;
}a[N];

int cnt = 0, ans = INT_MAX;
void dfs(Node *head, int c)
{
    if (c == -1)
    {
        ans = min(ans, cnt ^ head->val);
        // cout << cnt << " " << ans << endl;
        cnt ++;
        return;
    }

    Node p0, p1;
    Node *t0 = &p0, *t1 = &p1;

    while (head != NULL)
    {
        if (head->val & (1 << c))
        {
            t1->p = head;
            t1 = t1->p;
        }
        else
        {
            t0->p = head;
            t0 = t0->p;
        }
        head = head->p;
    }
    t0->p = t1->p = NULL;

    if (p0.p == NULL)
    {
        cnt += 1 << c;
        dfs(p1.p, c - 1);
    }
    else if (p1.p == NULL)
    {
        dfs(p0.p, c - 1);
        cnt += 1 << c;
    }
    else
    {
        dfs(p1.p, c - 1);
        dfs(p0.p, c - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].val;
        a[i - 1].p = &a[i];
    }
    a[n].p = NULL;

    dfs(a[0].p, 29);
    cout << ans << endl;
}