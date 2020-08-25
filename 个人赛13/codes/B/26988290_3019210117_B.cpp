#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long int n,x,y,z,ans=1000000000;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld%lld%lld",&x,&y,&z);
        ans=min(ans,x*x+y*y+z*z);   
    }
    printf("%.3lf\n",sqrt(ans));
    return 0;
}