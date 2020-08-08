#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
inline int readint(){
    int ret = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll(){
    ll ret = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
char n[300100];
int link[300100][2]; // 0 偶数 1 奇数
int cnt0, cnt1;
int cur0, cur1;
int main(){
    int T = readint();
    while(T--){
        scanf("%s", n);
        int len = strlen(n);
        cnt0 = cnt1 = 0;
        for(int i = 0; i < len; i++){
            if((n[i] - '0') % 2 == 0){
                ++cnt0;
                link[cnt0][0] = n[i] - '0';
            }
            else{
                ++cnt1;
                link[cnt1][1] = n[i] - '0';
            }
        }
        cur0 = cur1 = 1;
        while(cur0 <= cnt0 && cur1 <= cnt1){
            if(link[cur0][0] < link[cur1][1]){
                printf("%d", link[cur0][0]);
                ++cur0;
            }
            else{
                printf("%d", link[cur1][1]);
                ++cur1;
            }
        }
        while(cur0 <= cnt0){
            printf("%d", link[cur0][0]);
            ++cur0;
        }
        while(cur1 <= cnt1){
            printf("%d", link[cur1][1]);
            ++cur1;
        }
        printf("\n");
    }
    return 0;
}