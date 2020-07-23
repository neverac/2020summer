#include <bits/stdc++.h>
#define mod 998244353
#define LL long long
using  namespace std;
const int maxn = 1e5+1000;
LL a[maxn],mm,ans;
int n;
LL f[30],x,cnt[maxn],y;
void work(){
//    ans = 0;
//    for (int i=1;i<=n;i++){
//        LL x = a[i],wei = 1;
//        while (x){
//            int now = x%10;
//            LL k = (n*now) %mod;
//            ans = (ans + (k*wei)%mod)%mod;
//            ans = (ans + (k*(wei*10)%mod))%mod;
//
//            wei = (wei*100)%mod;
////            x/= 10;
////
////        }
////    }
    for (int i=1;i<=n;i++){
        x = a[i];
        int flag = 0;
        while (x){
            y = x%10;
            x/=10;

            flag++;
            for (int j = 1;j<=10;j++){
                if (j>=flag){
                    ans += y * cnt[j] * f[flag <<1];
                    ans += y * cnt[j] * f[(flag <<1) - 1];
                }
                else
                    ans += y * 2 * cnt[j] * f[flag + j];
                ans %= mod;
            }
        }
    }
}
void init(){
    f[1] = 1;
    for (int i= 2;i<=24;i++)
        f[i] = f[i - 1] * 10 % mod;

}
void read(){
    for (int i=1;i<=n;i++){
        cin >> a[i];
        int tot = 0;
        x = a[i];
        while (x){
            tot++;
            x/=10;
        }
        cnt[tot]++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    init();
    read();
    work();

    cout << ans;
    return 0;
}