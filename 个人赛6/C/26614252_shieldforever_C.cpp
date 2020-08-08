#include<bits/stdc++.h>
using namespace std;
#define N 100010
int f[N];
int findx(int x){
    if(f[x] == x) return x;
    else return f[x] = findx(f[x]);
}
    
int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) f[i] = i;
    int num = 0;
    for(int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        int fx = findx(x), fy = findx(y);
        if(fx != fy) ++num, f[fx] = fy;
    }
    printf("%d\n", m - num);
    return 0;
}