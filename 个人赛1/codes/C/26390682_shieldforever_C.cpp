#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N], q[N], p[N], tot = 1;
int n;

bool solve(){
    for(int i = 1; i <= n; i++){
        if(q[i] > q[i - 1]){
            a[i] = q[i];
            p[q[i]] = 1;
        }
        else{
            int flg = 0;
            while(tot < q[i]){
                if(p[tot] == 0) break;
                ++tot;
            }
            if(tot == q[i]) return false;
            else{
                a[i] = tot; p[tot] = 1;
            }
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1; i <= n; i++) scanf("%d", &q[i]);
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        tot = 1;
        if(!solve()) printf("-1\n");
        else {
            for(int i = 1; i <= n; i++) printf("%d ", a[i]);
            cout<<endl;
        }
    }
    return 0;
}
/*
4
5
1 3 4 5 5
4
1 1 3 4
2
2 2
1
1


1 3 4 5 2 
-1
2 1 
1 
*/