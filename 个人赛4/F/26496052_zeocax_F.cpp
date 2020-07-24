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
int main(){
    ll k = readll(), n = readll(), s = readll(), p = readll();
    ll sheetsperperson = (n - 1) / s + 1;
    ll packsintotal = (sheetsperperson * k - 1) / p + 1;
    printf("%lld", packsintotal);
    return 0;
}