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
char str[110];
int main(){
    int n = readint();
    scanf("%s", str + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(str[i] == '-'){
            if(ans > 0)
                --ans;
        }
        else if(str[i] == '+'){
            ++ans;
        }
    }
    printf("%d", ans);
    return 0;
}