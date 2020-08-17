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

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int k, l;
        scanf("%d %d", &k, &l);
        if(l >= 2000){
            printf("-1\n");
            continue;
        }
        int n = 1999;
        printf("%d\n", n);
        printf("-1 ");
        int tmp = 1999 + k;
        for(int i = 2; i < n; ++i)
        {
            printf("%d ", tmp / 1998);
        }
        int last = tmp % 1998 + tmp / 1998;
        printf("%d", last);
        printf("\n");
    }
    
    return 0;
}