#include<stdio.h>
#include<string.h>
typedef long long LL;
int main(){
    int d,p[600],growth[600];
    long long int money=100,stock=0,temp;
    scanf("%d",&d);
    for(int i=1;i<=d;i++){
        scanf("%d",&p[i]);
    }
    p[d+1]=-1;
    p[0]=1000;
    for(int i=0;i<=d;i++){
        if(p[i+1]>=p[i]){
            growth[i]=1;
        }else if(p[i+1]<p[i]){
            growth[i]=-1;
        }
    }
    for(int i=1;i<=d;i++){
        if(growth[i]==1&&growth[i-1]==-1){
            if(money>=p[i]){
                temp=money/p[i];
                if(temp>=100000){
                    temp=100000;
                }
                stock=temp;
                money-=p[i]*temp;
            }
        }
        if(growth[i]==-1&&growth[i-1]==1){
                money+=p[i]*stock;
                stock=0;
        }
    }
    printf("%lld\n",money);
    return 0;
}