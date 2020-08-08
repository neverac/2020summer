#include <iostream>
using namespace std;
int a[110],b[110];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin >> n;
    for (int i=1;i<=n;i++)cin >> a[i];
    for (int i=1;i<=n;i++)cin >> b[i];
    int in1=1,in2=1;
    while (in1<=n && in2 <=n){
        if (a[in1]<b[in2]) in1++;else in2++;
    }
    if (in1>n) cout << n-in2+1 << endl;
    else cout << n-in1+1 << endl;
}