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
#include <set>
#define ll long long
#define N 500
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

int n;

int peice[N];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &peice[i]);
    }
    int ans = INF;
    int start = 1, end = 1, tmp = peice[1];
    if(n == 1){
        printf("360\n");
        return 0;
    }
    while (end < n)
    {
        end++;
        tmp = tmp + peice[end];
        ans = min(ans, abs(180 - tmp));
        while (tmp > 180)
        {
            tmp -= peice[start];
            start++;
            ans = min(ans, abs(180 - tmp));
        }
    }
    printf("%d", ans * 2);
    return 0;
}