#include <iostream>
using namespace std;
int main(){
    int T,n,k,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        a=k/(n-1);
        b=k-a*(n-1);
        if(b==0){
            b--;
        }
        b+=a*n;
        printf("%d\n",b);
    }
    return 0;
}