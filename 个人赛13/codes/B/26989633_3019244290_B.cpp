#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#define Maxn 100000007
#define ll long long

using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    double dis=0x3f3f3f3f;
    for (int i=1;i<=n;i++) {
        double x,y,z;
        scanf("%lf%lf%lf",&x,&y,&z);
        dis= min(dis,sqrt(x*x+y*y+z*z));
    }
    printf("%.3lf\n",dis);
    return 0;
}
