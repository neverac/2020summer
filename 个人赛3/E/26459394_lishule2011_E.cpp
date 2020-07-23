#include <bits/stdc++.h>
#define mod 998244353
#define LL long long
using  namespace std;
const int maxn = 2e5+1000;
LL a[maxn],b[maxn],mm,ans,k;
int n;
LL f[30],x,cnt[maxn],y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];

    LL x = 0 ,y = 0;
    for (int i= 1;i<=n;i++){
        
        
        LL newa = max(x, y + a[i]);
        LL newb = max(y, x + b[i]);
        x = newa;
        y = newb;
//        cout << x << y << endl;
    }
    cout << max(x,y);
    return 0;
}