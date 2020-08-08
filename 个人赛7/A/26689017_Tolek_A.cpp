#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
typedef long long ll;
vector<int> vec[30];
int k, sum[30][N];
char op[N];
int main()
{
    scanf("%d%s", &k, op + 1);
    for (int i = 1; op[i]; i++) {
        vec[op[i] - 'a'].push_back(i);
        for (int j = 0; j < 26; j++) sum[j][i] = sum[j][i - 1] + (op[i] == 'a' + j);
    }
    // cout << vec['h' - 'a'][0] << endl;
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; op[j]; j++) {
            int now = sum[i][j];
            if (now == 0) continue;
            if (now <= k) {
                ans += vec[i][now - 1];
                // cout << (char)(i + 'a') << " " << 1 << " " << vec[i][now - 1] << endl;
            } else {
                ans += vec[i][now - 1] - vec[i][now - k - 1];
                // cout << "P " << (char)(i + 'a') << " " << vec[i][now - k - 1] + 1 << " " << vec[i][now - 1] << endl;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}