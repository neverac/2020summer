#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
vector <int> G[maxn];
int cnt[maxn],seq[maxn],n;

//int a[maxn],b[maxn];
//void work(){
//    int n;
//    int cnt = 0,flag = 0;
//    memset(a,0,sizeof(a));
//    memset(b,0,sizeof(b));
//    priority_queue <int> Q;
//    cin >> n;
//    for (int i=1;i<=n;i++)
//        cin >> a[i];
//    for (int i=1;i<=n;i++){
//        while (cnt < a[i]){
//            ++cnt;
//            Q.push(cnt);
//        }
//        if (Q.empty())
//            flag = 1;
//        else{
//            b[i] = Q.top();
//            Q.pop();
//        }
////        if (flag == 1)
////            cout << -1 << endl;
////        else{
////            for (int i=1;i<=n;i++)
////                cout << b[i] <<' ';
////            cout << endl;
////        }
//    }
//    if (flag == 1)
//        cout << -1 << endl;
//    else{
//        for (int i=1;i<=n;i++)
//            cout << b[i] <<' ';
//        cout << endl;
//    }
//}

void init(){
    cin >> n;
    for (int i = 0 ;i<n-2;i++){
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back(y);
        G[x].push_back(z);
        G[y].push_back(x);
        G[y].push_back(z);
        G[z].push_back(x);
        G[z].push_back(y);
        cnt[x]++,cnt[y]++,cnt[z]++;
    }
}

void work(){
    int fir,sec;
    for (int i=1;i<=n;i++){
        if (cnt[i] == 1){
            seq[i] = 1;
            fir = i;
            break;
        }
    }

    int l1 = G[fir].size();
    for (int i=0;i<l1;i++){
        if (cnt[G[fir][i]] == 2){
            sec = G[fir][i];
            seq[G[fir][i]] = 1;
            break;
        }
    }
    cout << fir << ' ' << sec;

    for (int i = 3;i<=n;i++){
        int pp ;
        for (int j = 0; j < G[fir].size(); j++){
            if (!seq[G[fir][j]]){
                cout << ' ' << G[fir][j];
                seq[G[fir][j]] = 1;
                pp = G[fir][j];
                break;
            }
        }
        fir = sec;
        sec = pp;
        //
    }


}

//void finish(){
//    for (int i = 3;i<=n;i++){
//        int a ;
//        for (int j = 0;j<v[t1].size();j++)
//    }
//}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    work();
//    finish();
    return 0;

}