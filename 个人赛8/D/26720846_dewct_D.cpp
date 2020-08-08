#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a = "";
        for (int i = 1; i <= 200; i++)
            a += 'a';
        cout << a << endl;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (a[x] == 'a')
                a[x] = 'b';
            else
            {
                a[x] = 'a';
            }
            cout << a << endl;
        }
    }
    return 0;
}