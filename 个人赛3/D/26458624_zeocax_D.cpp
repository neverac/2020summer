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
int b[200100];
int cnt1 = 0;
int cnt2 = 0;
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        b[i] = readint();
        if(b[i] == 1)++cnt1;
        else ++cnt2;
    }
    if(cnt1 == 0 || cnt2 == 0){
        for(int i = 1; i <= n; i++){
            printf("%d ", b[i]);
        }
        return 0;
    }
    printf("2 1 ");
    for(int i = 1; i <= cnt2 - 1; i++){
        printf("2 ");
    }
    for(int i = 1; i <= cnt1 - 1; i++){
        printf("1 ");
    }
    return 0;
}