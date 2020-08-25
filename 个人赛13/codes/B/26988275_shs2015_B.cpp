#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int SIZEN = 1010;
double ans = 1e30;
int main(){
int N;scanf("%d",&N);
for(int i = 1;i <= N;i++){
int x,y,z;scanf("%d%d%d",&x,&y,&z);
int dis = x * x + y * y + z * z;
ans = min(ans,1.*dis);
}
printf("%.3f\n",sqrt(ans));
return 0;
}