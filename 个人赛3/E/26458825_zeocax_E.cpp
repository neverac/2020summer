#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
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
int h[2][100100];
ll f[100100][2];
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        h[0][i] = readint();
    }
    for(int i = 1; i <= n; i++){
        h[1][i] = readint();
    }
    f[0][0] = 0;
    f[0][1] = 0;
    f[1][0] = h[0][1];
    f[1][1] = h[1][1];
    for(int i = 2; i <= n; i++){
        f[i][0] = max(max(f[i - 1][1], f[i - 2][0]), f[i - 2][1]) + h[0][i];
        f[i][1] = max(max(f[i - 1][0], f[i - 2][1]), f[i - 2][0]) + h[1][i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, f[i][0]);
        ans = max(ans, f[i][1]);
    }
    printf("%lld", ans);
    return 0;
}