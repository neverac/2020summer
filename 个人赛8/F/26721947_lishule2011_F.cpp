#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int flag;
        int res=0;
        for(int i=0;i<=9;i++)
            for (int j=0;j<=9;j++){
                flag=0;
                int cnt = 0;
                for (int k=0;k<s.length();k++)
                    if (!flag){
                        if (s[k] == '0'+i){
                            flag^=1;
                            cnt++;
                        }
                    }else{
                        if (s[k] == '0'+j){
                            flag^=1;
                            cnt++;
                        }
                    }
                if (cnt%2==1) cnt--;
                res = max(res,cnt);
            }
        for (int i=0;i<=9;i++){
            int cnt = 0;
            for (int k=0;k<s.length();k++)
                if (s[k] == '0'+i) cnt++;
            res=max(res,cnt);
        }
        cout << s.length()-res << endl;

    }
}

