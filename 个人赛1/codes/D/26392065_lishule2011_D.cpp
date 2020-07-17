#include <bits/stdc++.h>
using namespace std;
const int maxn =110;

int a[maxn],b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,h;
    cin >> n >> m >> h;
    for (int i=1;i<=m;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
        cin >> b[i];

    for (int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h;
            cout << (h == 1 ? min(a[j], b[i]) : 0 )<< ' ';
        }
        cout << endl;
    }
    return 0;

}