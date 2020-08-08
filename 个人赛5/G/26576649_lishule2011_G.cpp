#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+300;
const int maxxx = 2e6;
int ans[maxxx],cnt;
char s[maxn];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        cin >> s+1;
        n=strlen(s+1);
        cnt = 0;
        for (int i =1;i<=n-4;i++)
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e')
                ans[++cnt] = i+2,s[i+2]='@';

        for (int i =1;i<=n-2;i++){
            if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
                s[i+1]='@',ans[++cnt] = i+1;
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
                s[i+1]='@',ans[++cnt] = i+1;
        }

        cout << cnt << endl;
        for (int i=1;i<=cnt;i++) cout << ans[i] <<' ';
        cout << endl;

    }
}
