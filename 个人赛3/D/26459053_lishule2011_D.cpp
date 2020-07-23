#include <bits/stdc++.h>
#define mod 998244353
#define LL long long
using  namespace std;
const int maxn = 1e5+1000;
LL a[maxn],mm,ans,k;
int n;
LL f[30],x,cnt[maxn],y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    memset(a,0, sizeof(a));
    for (int i=1;i<=n;i++){
        cin >> k;
        a[k]++;
    }
    if (a[2]-- >0) cout << 2 <<' ';
    if (a[1]-- >0) cout << 1 <<' ';
    while(a[2]-- >0) cout << 2 <<' ';
    while(a[1]-- >0) cout << 1 <<' ';

    return 0;
}