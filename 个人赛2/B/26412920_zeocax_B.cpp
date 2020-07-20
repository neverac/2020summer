#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
bool vis[65536];
int main(){
    int A, B, C, S;
    while(scanf("%d", &A)){
        if(A == 0)break;
        scanf("%d%d%d", &B, &C, &S);
        memset(vis, 0, sizeof vis);
        int ans0 = 65535;
        int ans1 = 65535;
        while(!vis[S]){
            vis[S] = true;
            ans0 = ans0 & (~S);
            ans1 = ans1 & S;
            S = (A * S + B) % C;
        }
        for(int i = 15; i >= 0; i--){
            if(ans0 & (1 << i)){
                printf("0");
            }
            else if(ans1 & (1 << i)){
                printf("1");
            }
            else{
                printf("?");
            }
        }
        printf("\n");
    }
    return 0;
}