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
#define N 610000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

struct Point{
    double x, y,z;
    double dis(Point p){
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
    }
} pos[N];

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    int n;
    while (~scanf("%d",&n))
    {
        for (int i = 1; i <= n;i++){
            scanf("%lf %lf %lf", &pos[i].x, &pos[i].y, &pos[i].z);
        }
        double ans = 100000000;
        Point e = {0.0, 0.0, 0.0};
        for (int i = 1; i <= n;i++){
            ans = min(ans, pos[i].dis(e));
        }
        printf("%.3lf\n", ans);
    }
    
    return 0;
}