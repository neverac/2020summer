#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],b[maxn];
void work(){
    int n;
    int cnt = 0,flag = 0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    priority_queue <int> Q;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++){
        while (cnt < a[i]){
            ++cnt;
            Q.push(cnt);
        }
        if (Q.empty())
            flag = 1;
        else{
            b[i] = Q.top();
            Q.pop();
        }
//        if (flag == 1)
//            cout << -1 << endl;
//        else{
//            for (int i=1;i<=n;i++)
//                cout << b[i] <<' ';
//            cout << endl;
//        }
    }
    if (flag == 1)
        cout << -1 << endl;
    else{
        for (int i=1;i<=n;i++)
            cout << b[i] <<' ';
        cout << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t -- ){
        work();
    }

    return 0;

}