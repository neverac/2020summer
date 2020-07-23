#include <bits/stdc++.h>
using  namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int count = 0;
    for (int i=0;i<n;i++){
        if (s[i]=='-' && count >0) count--;
        else if (s[i] == '+') count ++;
    }
    cout << count << endl;

    return 0;
}