#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
set<string> ssp;
vector<int> vec;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        ssp.insert(str);
    }
    for (string s : ssp) vec.push_back(s.length());
    sort(vec.begin(), vec.end());
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        // cout << vec[i] << " " << n << endl;
        if (vec[i] > n) break;
        n -= vec[i] + 1, ++ans;
    }
    printf("%d", ans);
    return 0;
}