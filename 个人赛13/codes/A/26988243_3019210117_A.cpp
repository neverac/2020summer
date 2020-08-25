#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long int t,n,m,x,y;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        if(n<x){
            printf("0\n");
        }else{
            if(x<=y){
                printf("%lld\n",m);
            }else{
                printf("%lld\n",min(m,(n+(m-1)*y)/x));
            }
        }
    }
    return 0;
}