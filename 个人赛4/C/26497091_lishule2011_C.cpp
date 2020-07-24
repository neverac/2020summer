#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string s;
int n,loc;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int tot = 0;
        cin >> n >> loc >> s;
        vector<int> a(s.size());
        for (int i = 0;i<s.size();i++) a[i] = tot = s[i] == '0'?tot+1:tot-1;
        int ans = 0;
        if(loc == 0) ans++;
        for (int i = 0; i < a.size(); i++){
            if (a[i] == loc && tot == 0){
                ans = -1;
                break;
            }
            if (tot && (loc - a[i]) % tot == 0 && (loc - a[i]) / tot >= 0) ans++;
        }
        cout << ans << endl;
    }
}
