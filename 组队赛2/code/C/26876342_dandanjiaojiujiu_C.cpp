#include<bits/stdc++.h>
using namespace std;
#define N 55
int a[N], n;
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    bool f = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(i == j || i == k || j == k) continue;
                if((a[i] - a[j]) % a[k] != 0) f = false;
            }
        }
    }
    if(f) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}