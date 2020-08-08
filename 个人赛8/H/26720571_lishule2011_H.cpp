#include<bits/stdc++.h>
using namespace std;
const int maxn =2e5+100;
int up[maxn],nxtup[maxn],a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >>a[i];
        up[i] = nxtup[i] = 1;
    }
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1]) up[i]=up[i-1]+1;
        if (a[i]>a[i-1]) nxtup[i] = nxtup[i-1]+1;
        if (a[i]>a[i-2]) nxtup[i] = max(up[i-2]+1,nxtup[i]);
    }

    int maxx = 0;
    for (int i=1;i<=n;i++){
        maxx=max(maxx,up[i]);
        maxx=max(maxx,nxtup[i]);
    }

    cout << maxx;
}