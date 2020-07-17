#include<bits/stdc++.h>
using namespace std;

#define N 1010
int p[N];

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }
    sort(p + 1, p + 1 + n);
    int ans = 0;
    for(int i = 1; i <= k; i++) ans += p[i];
    cout<<ans<<endl;
    return 0;
}