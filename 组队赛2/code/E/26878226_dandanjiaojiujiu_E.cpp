#include<bits/stdc++.h>
using namespace std;
int k, L;
void solve(){
    if(L >= 2000){
        cout<<"-1"<<endl; return ;
    }
    printf("1999\n-1 ");
    int s = k + 1999, cur = 0;
    for(int i = 1; i <= 1998; i++){
        if(cur + 1000000 > s){
            cout<<(s - cur);
            cur = s;
        }
        else{
            cout<<1000000;
            cur += 1000000;
        }
        if(i == 1998) cout<<endl;
        else cout<<' ';
    }
    return ;
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>k>>L;
        solve();
    }
    return 0;
}