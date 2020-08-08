#include<bits/stdc++.h>
using namespace std;
#define N 110
char s[N][N];
int a[N], n;

void init(){
    cin>>n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    return ;
}
void solve(){
    for(int i = 1; i < N; i++) s[0][i] = 'a';
    for(int i = 1; i < N; i++) printf("%c", s[0][i]);
    cout<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++){
            s[i][j] = s[i - 1][j];
        }
        char x;
        if(s[i - 1][a[i] + 1] == 'a') x = 'b';
        else x = 'a';
        for(int j = a[i] + 1; j < N; j++) s[i][j] = x;
        for(int j = 1; j < N; j++) printf("%c", s[i][j]);
        printf("\n");
    }
    return ;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        init();
        solve();
    }
    return 0;
}


