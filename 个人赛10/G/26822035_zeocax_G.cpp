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
struct Query{
    int num, pos;
    int id;
}query[110];
struct Num{
    int num, pos;
}a[110];
struct Ans{
    int num, pos;
}ans[110];
inline bool cmp1(Num a, Num b){
    return a.num == b.num ? a.pos < b.pos : a.num > b.num;
}
inline bool cmp2(Query a, Query b){
    return a.num == b.num ? a.pos < b.pos : a.num < b.num;
}
inline bool cmp3(Ans a, Ans b){
    return a.pos < b.pos;
}
int p[110];
int main(){
    int n = readint();
    for(int i = 1; i <= n; i++){
        a[i].num = readint();
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1, cmp1);
    int m = readint();
    for(int i = 1; i <= m; i++){
        query[i].num = readint();
        query[i].pos = readint();
        query[i].id = i;
    }
    sort(query + 1, query + m + 1, cmp2);
    int curnum = 0;
    for(int i = 1; i <= m; i++){
        while(curnum < query[i].num){
            ++curnum;
            ans[curnum].pos = a[curnum].pos;
            ans[curnum].num = a[curnum].num;
        }
        sort(ans + 1, ans + curnum + 1, cmp3);
        p[query[i].id] = ans[query[i].pos].num;
    }
    for(int i = 1; i <= m; i++){
        printf("%d\n", p[i]);
    }
    return 0;
}