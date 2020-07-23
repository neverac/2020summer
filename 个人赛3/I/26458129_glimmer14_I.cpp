#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == '-')
        {
            if (ans != 0) ans --;
        }
        else
        {
            ans ++;
        }
        
    }
    cout << ans << endl;
}