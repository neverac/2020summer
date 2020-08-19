#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int DP(int at, vector<int> vec)
{
    if (at == -1) return 0;
    vector<int> s1, s2;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] & (1 << at)) {
            s2.push_back(vec[i] & (~(1 << at)));
        } else {
            s1.push_back(vec[i]);
        }
    }
    if (s1.empty() || s2.empty()) {
        if (s1.empty()) return DP(at - 1, s2);
        return DP(at - 1, s1);
    }
    return min(DP(at - 1, s1), DP(at - 1, s2)) | (1 << at);
}
int n;
int main()
{
    vector<int> vec;
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), vec.push_back(x);
    printf("%d", DP(31, vec));
    return 0;
}