#include<bits/stdc++.h>
using namespace std;
#define N 1010
int g[N][N];
char s[N];
vector<int> x1, x2, yy, y2;
int n, m;

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        scanf("%s", s + 1);
        for(int j = 1; j <= m; j++){
            if(s[j] == '1') x1.push_back(i), yy.push_back(j);
            if(s[j] == '2') x2.push_back(i), y2.push_back(j);
        }
    }
    int ans= n * m;
    n = x1.size(), m = x2.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int o = abs((double)x1[i] - x2[j]) + abs((double)yy[i] - y2[j]) + 1;
            if(o < ans) ans = o;
        }
    }
    printf("%d\n", ans);
    return ;
}

int main(){
    solve();
    return 0;
}