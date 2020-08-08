#include<bits/stdc++.h>
using namespace std;
#define N 300030
char s[N];
int a[N], b[N], ans[N];
int n;

void solve(){
    a[0] = b[0] = 0;
    for(int i = 1; i <= n; i++){
        int x = s[i] - '0';
        if(x & 1) a[++a[0]] = x;
        else b[++b[0]] = x;
    }
    int x = 1, y = 1;
    for(int i = 1; i <= n; i++){
        if(x <= a[0] && y <= b[0]){
            if(a[x] < b[y]) ans[i] = a[x++];
            else ans[i] = b[y++];
        }
        else if(x > a[0]) ans[i] = b[y++];
        else ans[i] = a[x++];
    }
    for(int i = 1; i <= n; i++) printf("%d", ans[i]);
    cout<<endl;
    return ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%s", s + 1);
        n = strlen(s + 1);
        solve();
    }
}