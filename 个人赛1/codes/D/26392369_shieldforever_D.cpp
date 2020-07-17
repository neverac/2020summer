#include<bits/stdc++.h>
using namespace std;

int h[110][110], f[110], l[110], t[110][110];
int n, m, ll;

int main(){
    cin>>n>>m>>ll;
    for(int i = 1; i <= m; i++){
        scanf("%d", &f[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &l[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) scanf("%d", &t[i][j]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(t[i][j] == 0) continue;
            for(int k = 1; k <= ll; k++){
                if(f[j] < k || l[i] < k) break;
                else h[i][j]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", h[i][j]);
        }
        cout<<endl;
    }
    return 0;
}