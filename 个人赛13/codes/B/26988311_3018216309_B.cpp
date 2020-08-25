#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e6+10;
int x,y,z;
double minn=0x3f3f3f3f;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&x,&y,&z);
        minn=min(minn,sqrt((double)x*x+y*y+z*z));
    }
    printf("%.3lf",minn);
}

