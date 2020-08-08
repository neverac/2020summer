#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 100;
int sum[26][N];
int pos[26], nxt[N][26];
int n, k;
char s[N];

int main() {
    scanf("%d", &k);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[j][i] = sum[j][i-1];
        }
        sum[s[i]-'a'][i]++;

    }
    for (int i = n; i >= 1; i--) {
        pos[s[i]-'a'] = i;
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = pos[j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            int l = i, r = n;
            if (!nxt[i][j]) continue;
            else {
                l = nxt[i][j];
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (sum[j][mid] - sum[j][i-1] > k) r = mid - 1;
                    else l = mid;
                }
                ans += l - nxt[i][j]+ 1;
            }
        }
    }
    cout << ans << endl;
}