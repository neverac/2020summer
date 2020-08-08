#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e4;
const int limit = 1e5;
int a[maxn],flag[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++) flag[i] = (a[i+1]<a[i])? -1:1; //-1sell
    flag[0] = -1;
    flag[n] = -1;

//    for (int j=1;j<=n;j++)
//        cout << flag[j]<< ' ';
//    cout << endl;

    LL money = 100,num = 0;
    for (int i=1;i<=n;i++){
        if (flag[i] == 1 && flag[i-1] == -1)
            num = (money/a[i]>limit)?limit:money/a[i],money -= num*a[i];
        else if (flag[i] == -1 && flag[i-1] == 1)  money += num*a[i],num = 0;
    }
    cout << money << endl;

}