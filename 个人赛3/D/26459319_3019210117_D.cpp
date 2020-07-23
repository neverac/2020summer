#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,cnt1=0,cnt2=0,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x==1){
            cnt1++;
        }
        if(x==2){
            cnt2++;
        }
    }
    if(cnt2>0){
        printf("2 ");
        cnt2--;
    }
    if(cnt1>0){
        printf("1 ");
        cnt1--;
    }
    while(cnt2>0){
        printf("2 ");
        cnt2--;
    }
    while(cnt1>0){
        printf("1 ");
        cnt1--;
    }
    return 0;
}