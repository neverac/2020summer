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
    int ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
inline ll readll()
{
    ll ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
int main(){
    int n = readint();
    double ans = int_inf;
    for(int i = 1; i <= n; i++){
        int x = readint(), y = readint(), z = readint();
        double dis = sqrt(x * x + y * y + z * z);
        ans = min(ans, dis);
    }
    printf("%.3lf", ans);
    return 0;
}