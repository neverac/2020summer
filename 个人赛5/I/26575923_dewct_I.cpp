#include <bits/stdc++.h>
using namespace std;

string a;
queue<int> q1, q2;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a;
        while (!q1.empty())
            q1.pop();
        while (!q2.empty())
            q2.pop();
        int len = a.length();
        for (int i = 0; i < len; i++)
        {
            if ((a[i] - '0') % 2 == 0)
                q2.push(a[i] - '0');
            else if ((a[i] - '0') % 2 != 0)
                q1.push(a[i] - '0');
        }
        while (!q1.empty() || !q2.empty())
        {
            if (q1.empty())
            {
                cout << q2.front();
                q2.pop();
            }
            else if (q2.empty())
            {
                cout << q1.front();
                q1.pop();
            }
            else if (q1.front() <= q2.front())
            {
                cout << q1.front();
                q1.pop();
            }
            else
            {
                cout << q2.front();
                q2.pop();
            }
        }
        cout << endl;
    }
    return 0;
}