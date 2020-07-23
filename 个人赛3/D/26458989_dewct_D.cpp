#include <bits/stdc++.h>
using namespace std;

int num[233333];
queue<int> q1, q2;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 1)
            q1.push(1);
        else
            q2.push(2);
    }
    if (!q2.empty())
    {
        cout << 2 << " ";
        q2.pop();
        if (!q1.empty())
        {
            cout << 1 << " ";
            q1.pop();
        }
        while (!q2.empty())
            cout << 2 << " ", q2.pop();
        while (!q1.empty())
            cout << 1 << " ", q1.pop();
    }
    else
    {
        while (!q1.empty())
            cout << 1 << " ", q1.pop();
    }
    return 0;
}