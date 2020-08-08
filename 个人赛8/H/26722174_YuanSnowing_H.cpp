#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020],b[200020],c[200020],ans;
 
int main(){
    cin >> n;
    for(int i=1;i<=n;++ i){
    	cin >> a[i];
    	b[i] = c[i] = 1;
    }
    // cout << "jhhhhhhhh";
    ans = 1;
    for(int i=n-1;i>=1; -- i){
        if(a[i+1] > a[i]) b[i] = b[i+1]+1;
    }
    for(int i=2;i<=n;++ i){
        if(a[i] > a[i-1]) c[i]=c[i-1]+1;
    }
    for(int i=1;i<=n;++ i){
    	ans = max(ans,b[i]);
    	ans = max(ans,c[i]);
        if(i<=n-2 && a[i+2] > a[i]) ans = max(ans,b[i+2]+c[i]);
    }
    cout << ans << endl;
    return 0;
}