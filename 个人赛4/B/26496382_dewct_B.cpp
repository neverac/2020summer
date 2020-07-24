#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    int len = s.length();
    int a = s[len - 1] - '0';
    if (len > 1)
        a = (s[len - 2] - '0') * 10 + a;
    a %= 4;
    if (a == 0)
        cout << 4;
    else if (a == 1)
        cout << 0;
    else if (a == 2)
        cout << 0;
    else if (a == 3)
        cout << 0;
    return 0;
}