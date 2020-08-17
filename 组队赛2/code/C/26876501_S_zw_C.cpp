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
#define N 2100
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
//ll mod = 12;
using namespace std;

int a[N];

int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    bool flag = true;
    for (int i = 1; i <= n;i++){
        for (int j = i+1; j <= n;j++){
            for (int k = j + 1; k <= n;k++){
                int x = a[i], y = a[j], z = a[k];
                if((x-y)%z || (x-z)%y || (y-z)%x) {
                    flag = false;
                }
            }
        }
    }
    if(flag){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}