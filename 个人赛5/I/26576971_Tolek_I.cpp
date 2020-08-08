#include <bits/stdc++.h>
using namespace std;
char op[300005], ans[300005];
int n;
vector<int> vec[2];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", op + 1);
        vec[0].clear();
        vec[1].clear();
        for (int i = 1; op[i]; i++) {
            if ((op[i] - '0') & 1)
                vec[1].push_back(op[i]);
            else
                vec[0].push_back(op[i]);
        }
        reverse(vec[0].begin(), vec[0].end());
        reverse(vec[1].begin(), vec[1].end());
        while (!vec[0].empty() || !vec[1].empty()) {
            if (vec[0].empty()) {
                printf("%c", vec[1].back()), vec[1].pop_back();
                continue;
            }
            if (vec[1].empty()) {
                printf("%c", vec[0].back()), vec[0].pop_back();
                continue;
            }
            if (vec[0].back() > vec[1].back()) {
                printf("%c", vec[1].back()), vec[1].pop_back();
            } else {
                printf("%c", vec[0].back()), vec[0].pop_back();
            }
        }
        printf("\n");
    }
}