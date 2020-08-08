#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define N 22000
#define mid ((l + r) >> 1)
#define lc (rt << 1)
#define rc ((rt << 1) | 1)
#define tree_len (r - l + 1)
#define left_len (mid - l + 1)
#define right_len (r - mid)
#define tozero(x) memset(x, 0, sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e5 + 7;
using namespace std;

int a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    int a_max = -1, b_max = -1;
    for (int i = 1; i <= n;i++){
        scanf("%d", a + i);
        a_max = max(a[i], a_max);
    }
    for (int i = 1; i <= n;i++){
        scanf("%d", b + i);
        b_max = max(b_max, b[i]);
    }
    int aPos = 1, bPos = 1;
    for (aPos = 1; aPos <= n;aPos++){
        if(a[aPos] > b_max){
            break;
        }
    }
    for (bPos = 1; bPos <= n;bPos++){
        if(b[bPos] > a_max){
            break;
        }
    }
    if(aPos != n+1){
        printf("%d\n", n - aPos + 1);
    }else{
        printf("%d\n", n - bPos + 1);
    }
    return 0;
}