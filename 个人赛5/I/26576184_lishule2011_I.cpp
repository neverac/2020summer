#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+1000;
int odd[maxn],even[maxn],cnt2,cnt1;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t ;
    while (t--){
        memset(odd,0,sizeof(odd));
        memset(even,0,sizeof(even));
//        memset(ans,0,sizeof(even));
        cnt1 = cnt2 = 0;
        cin >> s;
//        cout <<" lsl" << s << endl;
        for (int i=0;i<s.length();i++)
            if ((s[i]-'0')%2 == 0) even[++cnt2] = (s[i] - '0');
            else odd[++cnt1] = (s[i] - '0');
        int now1 = 1, now2 = 1;
//        cout << "fuck" << endl;
//        for (int i=1;i<=cnt1;i++) cout << odd[i]<<' ';cout << endl;
//        for (int i=1;i<=cnt2;i++) cout << even[i]<<' ';cout << endl;
        if (cnt1 == 0) {
            for (int i=1;i<=cnt2;i++) cout << even[i];
            cout << endl;
            continue;
        }if (cnt2 == 0) {
            for (int i=1;i<=cnt1;i++) cout << odd[i];
            cout << endl;
            continue;
        }
        while (now1<=cnt1 || now2<=cnt2){
            if(now1 > cnt1) {
                for (int i=now2;i<=cnt2;i++) cout << even[i];
                break;
            }
            if(now2 > cnt2) {
                for (int i=now1;i<=cnt1;i++) cout << odd[i];
                break;
            }
//            cout << odd[now1] << ' '<<even[now2] << endl;
            if (odd[now1]<even[now2]){
                cout << odd[now1];
                now1++;
            }else{
                cout << even[now2];
                now2++;
            };
        }
        cout << endl;
    }

}