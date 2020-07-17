#include <iostream>
#include <algorithm>
using namespace std;
int p[100100];
int ans[100100];
bool vis[100100];
int main(){
    int T; scanf("%d", &T);
    while(T--){
        bool OK = true;
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &p[i]);
            ans[i] = 0;
            vis[i] = false;
        }
        p[0] = 0;
        for(int i = 1; i <= n; i++){
            if(p[i] > p[i - 1]){
                ans[i] = p[i];
                vis[p[i]] = true;
            }
        }
        int cur = 1;
        for(int i = 1; i <= n; i++)
        if(!ans[i]){
            while(vis[cur])++cur;
            ans[i] = cur;
            vis[cur] = true;
        }
        int mx = 0;
        for(int i = 1; i <= n; i++){
            mx = max(mx, ans[i]);
            if(mx != p[i]){
                OK = false;
                break;
            }
        }
        if(!OK)printf("-1\n");
        else{
            for(int i = 1; i <= n; i++){
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}