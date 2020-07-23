#include<bits/stdc++.h>
using namespace std;
#define N 200020
int a[N], n, p[N];
void solve(){
    int x = 0, y = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1) ++x;
        if(a[i] == 2) ++y;
    }
    if(y == 0){
        for(int i = 1; i <= n; i++)printf("1 ");
        return ;
    }
    else{
        int c = 0;
        p[++c] = 2; --y;
        if(x == 0){
            for(int i = 1; i <= n; i++) printf("2 "); printf("\n");
            return ;
        }
        p[++c] = 1;
        --x;
        while(y > 0){
            p[++c] = 2; --y;
        }
        while(x > 0){
            --x; p[++c] = 1;
        }
        for(int i = 1; i <= c; i++)printf("%d ", p[i]);
    }
    printf("\n");
    return ;
}
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    solve();
    return 0;
}