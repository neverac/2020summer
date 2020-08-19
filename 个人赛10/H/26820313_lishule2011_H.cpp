#include <bits/stdc++.h>
using namespace std;
int a[1000],sum[1000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }
    int ans = 180;
    for (int i=1;i<=n;i++)
        for (int j = i;j<=n;j++){
            if (abs(sum[j]-sum[i-1]-180)<ans)
                ans = abs(sum[j]-sum[i-1]-180);
        }
    cout << ans*2 << endl;
}