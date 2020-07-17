#include<iostream>
using namespace std;
int a[100003];
int main(){
    int t,x,n;
    scanf("%d",&t);
    while(t--){
        bool flag=false;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x<i){
                flag=true;
            }
            if(x!=i){
                swap(a[x],a[i]);
            }
        }
        if(flag){
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}