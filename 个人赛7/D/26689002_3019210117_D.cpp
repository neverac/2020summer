#include <iostream>
using namespace std;
long long int A,ans,powi,sum;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&A);
        ans=1;
        while(A%2==0){
            A>>=1;
        }
        for(int i=3;i<=7;i+=2){
            powi=sum=1;
            while(A%i==0){
                A/=i;
                powi*=i;
                sum+=powi;
            }
            ans*=sum;
        }
        printf("%lld\n",ans);
    }
    return 0;
}