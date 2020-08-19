#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
char s[N];
int sum[N][26];

int main()
{
    int q, l, r;
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    scanf("%d", &q);

    for (int i = 1; i <= len; i ++)
        sum[i][s[i] - 'a'] = 1;
    
    for (int i = 1; i <= len; i ++)
        for (int j = 0; j < 26; j ++)
            sum[i][j] += sum[i - 1][j];
 
    for (int i = 0; i < q; i ++)
    {
        scanf("%d %d", &l, &r);

        if (l == r || s[l] != s[r])
        {
            cout << "Yes" << endl;
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i ++)
            cnt += (sum[r][i] > sum[l - 1][i]);
        cout << (cnt > 2 ? "Yes" : "No") << endl;
    }
}