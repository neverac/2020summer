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
int a[110];
char str[110][210];
int main(){
    srand(19260817);
    int T = readint();
    while(T--){
        int n = readint();
        for(int i = 1; i <= n; i++){
            a[i] = readint();
        }
        a[0] = a[n + 1] = 0;
        for(int i = 0; i < 100; i++)
        for(int j = 0; j < 200; j++){
            str[i][j] = rand() % 26 + 'a';
        }
        for(int i = 1; i <= n + 1; i++){
            int len = max(a[i - 1], a[i]);
            if(len == 0) ++len;
            int cur = a[i - 1];
            for(int j = 0; j < cur; j++){
                str[i][j] = str[i - 1][j];
            }
            while(cur < len){
                str[i][cur] = ((str[i - 1][cur] - 'a') + 1) % 26 + 'a';
                ++cur;
            }
            for(int j = 0; j < len; j++){
                printf("%c", str[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}