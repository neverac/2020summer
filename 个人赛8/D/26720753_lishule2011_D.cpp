#include<bits/stdc++.h>
using namespace std;
const int len=100;
char f(char ch){
    if (ch == 'a')return 'b';
    else return 'a';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        cout << s << endl;

        for (int i=1;i<=n;i++){
            int x;
            cin >> x;
            for (int i=x;i<len;i++)
                s[i] = f(s[i]);
            cout << s << endl;
        }
    }
}