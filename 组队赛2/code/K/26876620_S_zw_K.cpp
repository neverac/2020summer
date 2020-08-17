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

int arr[N];
int n;
int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            scanf("%d", &arr[i]);
        sort(arr + 1, arr + 1 + n);
        priority_queue<int,vector<int>,greater<int> >Q;
        for (int i = 1; i <= n;i++)
            Q.push(arr[i]);
        int ans = 0;
        for (int i = 1; i < n;i++){
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            Q.push(a + b);
            ans += a + b;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}