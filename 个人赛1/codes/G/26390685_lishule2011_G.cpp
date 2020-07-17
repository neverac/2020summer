#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e5+100;
LL n,m;
LL a[maxn],b[maxn],ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL maxx = 0;
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        cin >> a[i];
        ans+= a[i] * m;
        if (a[i] > maxx) maxx = a[i];
    }

    int flag = 1;
    for (int i=1;i<=m;i++){
        cin >> b[i];
        if (b[i] < maxx) flag = 0;
    }

    if (flag ){
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + m + 1);
        for (int i=2;i<=m;i++){
            ans+= b[i] - a[n];
        }

        if (b[1] != a[n]){
            ans += b[1] - a[n - 1];
        }
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0 ;


}

