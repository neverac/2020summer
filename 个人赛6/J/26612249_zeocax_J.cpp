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
int main(){
    int n = readint(), k = readint();
    int pocket_cnt = 0;
    for(int i = 1; i <= n; i++){
        int num = readint();
        pocket_cnt += (num - 1) / k + 1;
    }
    int ans = (pocket_cnt - 1) / 2 + 1;
    printf("%d", ans);
    return 0;
}