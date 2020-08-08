#include <bits/stdc++.h>
using namespace std;

const int N = 100, M = 60;
char s[2][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int p = 0;
        for (int i = 0; i < M; i ++)
            s[p][i] = 'a';
        s[p][M] = '\0';
        cout << s[p] << endl;
        while (n--)
        {
            cin >> a;
            int pp = p ^ 1;
            for (int i = 0; i < a; i ++)
                s[pp][i] = s[p][i];
            s[pp][a] = s[p][a] == 'a' ? 'b' : 'a';
            for (int i = a + 1; i < M; i ++)
                s[pp][i] = 'a';
            s[p][M] = '\0';

            p = pp;
            cout << s[p] << endl;
        }
        
    }
    
}