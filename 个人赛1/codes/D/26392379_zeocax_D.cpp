#include <iostream>
#include <algorithm>
using namespace std;
int a[110], b[110];
int ans[110][110];
int main(){
    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= m; i++)scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        scanf("%d", &ans[i][j]);
        if(!ans[i][j])continue;
        else{
            ans[i][j] = min(a[j], b[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}