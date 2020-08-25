#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int a[1010],cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        string str;
        cin >> str;
        if (!mp[str]){
            mp[str] = 1;
            a[++cnt] = str.size();
        }
    }
//    cout << a[1];
    sort(a+1,a+1+cnt);
    int ans = 0;
    for (int i=1;i<=cnt;i++){
        if (n-a[i] == 0){
            cout << ++ans;
            return 0;
        }
        if (n-a[i]-1<0) {
            cout << ans ;
            return 0;
        }
        ans++;
        n-=a[i]+1;
    }
    cout << ans ;

}