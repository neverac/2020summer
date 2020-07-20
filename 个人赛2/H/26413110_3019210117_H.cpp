#include <iostream>
using namespace std;
int main(){
    long long int t1,t2,x,y;
    scanf("%lld%lld%lld%lld",&t1,&t2,&x,&y);
    long long int l=1,r=10000000000,mid;
    while(l<r){
        mid=(l+r)/2;
        if(mid-mid/(x*y)>=t1+t2&&mid-mid/x>=t1&&mid-mid/y>=t2){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
    return 0;
}