#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int n;
double ans;

int main(){
    ans=1e16;
    double t1,t2,t3;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf%lf",&t1,&t2,&t3);
        ans=min(ans,sqrt(t1*t1+t2*t2+t3*t3));
    }
    printf("%.3f",ans);
    //while(1);
}
