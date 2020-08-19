#include <iostream>
#include <cmath>
using namespace std;
int num[365],n; 
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int ans=500,sum=0;
    for(int i=0;i<n;i++){
        sum=num[i];
        ans=min(abs(180-sum),ans);
        for(int j=i+1;j!=i&&j<n;j=(j+1)%n){
            sum+=num[j];
            ans=min(abs(180-sum),ans);
        }
    }
    printf("%d\n",2*ans);
    return 0; 
}