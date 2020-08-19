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
int a[400], sum[400];
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        a[i] = readint();
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 360;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        if(i <= j){
            ans = min(ans, abs(360 - 2 * (sum[j] - sum[i - 1])));
        }
        else{
            ans = min(ans, abs(360 - 2 * (sum[j] + 360 - sum[i - 1])));
        }
    }
    printf("%d", ans);
    return 0;
}