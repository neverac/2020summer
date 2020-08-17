#include <iostream>
using namespace std;
long long int ansarr[2000];
int main(){
   // freopen("in.txt","r",stdin);
    ansarr[1]=-1;
    for(int i=2;i<2000;i++){
        ansarr[i]=1;
    }
    ansarr[1999]=2;
    long long int t,k,l,w;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&k,&l);
        if(l>=2000){
            printf("-1\n");
        }else{
            printf("1999\n");
            ansarr[1999]+=k;
            for(w=1999;;w--){
                if(ansarr[w]<1000000){
                    break;
                }
                ansarr[w-1]+=ansarr[w]-999999;
                ansarr[w]=999999;
            }
            for(int i=1;i<2000;i++){
                if(i!=1){
                    printf(" ");
                }
                printf("%lld",ansarr[i]);
            }
            printf("\n");
            while(w<2000){
                ansarr[w++]=1;
            }
            ansarr[1999]=2;
        }
    }
    return 0;
}