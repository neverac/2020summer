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
#define N 5500
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

int arr[N];
int dp[N][N];
int main()
{
    int ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1;i<=n;i++){
        for (int j = 1; j <= n;j++){
            dp[i][j] = 2;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int dis = arr[j] - arr[i];
            int k = lower_bound(arr + 1, arr + 1 + n, arr[j] + dis) - arr;
            if(k>=1 && k <= n && arr[k] == arr[j]+dis){
                dp[i][j] = max(dp[i][j], dp[j][k] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
        printf("%d\n", ans);
    return 0;
}