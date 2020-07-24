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
int bignum[100100];
int main(){
    string str;
    cin >> str;
    int len = str.length();
    for(int i = len - 1; i >= 0; i--){
        bignum[len - i - 1] = str[i] - '0';
    }
    int mod = 4;
    int num = 0;
    for(int i = len - 1; i >= 0; i--){
        num = num * 10 + bignum[i];
        num = num % mod;
    }
    int num4 = bignum[0] % 2;
    int ans = 0;
    ans += 1;
    if(num == 0){
        ans += 1;
        ans += 1;
    }
    else if(num == 1){
        ans += 2;
        ans += 3;
    }
    else if(num == 2){
        ans += 4;
        ans += 4;
    }
    else if(num == 3){
        ans += 3;
        ans += 2;
    }
    if(num4 == 0){
        ans += 1;
    }
    else{
        ans += 4;
    }
    printf("%d", ans % 5);
    return 0;
}