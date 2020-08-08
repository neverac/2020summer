#include <bits/stdc++.h>
using namespace std;

string a;

queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        while (!q.empty())
            q.pop();
        cin >> a;
        int len = a.length();
        for (int i = 0; i < len; i++)
        {
            if (a[i] == 'o' && a[i + 1] == 'n' && a[i + 2] == 'e')
                q.push(i + 2), i += 2;
            else if (a[i] == 't' && a[i + 1] == 'w' && a[i + 2] == 'o')
            {
                if (a[i + 3] == 'n' && a[i + 4] == 'e')
                    q.push(i + 3), i += 4;
                else
                    q.push(i + 2), i += 2;
            }
        }
        cout << q.size() << endl;
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}