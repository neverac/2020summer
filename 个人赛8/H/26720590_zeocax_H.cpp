#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
int a[200100];
int f1[200100], f2[200100];
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        a[i] = readint();
    }
    a[0] = a[n + 1] = int_inf;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > a[i - 1])f1[i] = f1[i - 1] + 1;
        else f1[i] = 1;
        ans = max(ans, f1[i]);
    }
    for(int i = n; i >= 1; i--){
        if(a[i] < a[i + 1])f2[i] = f2[i + 1] + 1;
        else f2[i] = 1;
    }
    for(int i = 2; i <= n - 1; i++){
        if(a[i + 1] > a[i - 1]){
            ans = max(ans, f1[i - 1] + f2[i + 1]);
        }
    }
    printf("%d", ans);
    return 0;
}