#include <iostream>
using namespace std;




long long f[500],g[500];
int a[500];
long long cur = 100;
long long cus = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++) {
        cin >> a[i] ;
        f[i] = g[i] = -100000000;
    }
    for (int i = 1; i <= n; i++) {
        int j = i;
        int mx = a[i];
        while (j + 1 <= n && a[j+1] > mx) mx = a[j+1],j++;
        if (j == i) continue;
        cur = (min(cur / a[i], 100000ll) * 1ll * a[j]) + (cur - min(cur/a[i],100000ll) * a[i]);
        i = j;
    }
    cout << cur << endl; 
}

