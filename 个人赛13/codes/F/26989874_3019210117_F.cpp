#include <iostream>
using namespace std;
const int tagx[4]={8,3,45,100},ansx[4]={1,2,1,2};
int main(){
    //freopen("out.txt","w",stdout);
    int k;
    scanf("%d",&k);
    printf("%d %d\n",4*k,2*k);
    for(int j=0;j<4;j++){
        for(int i=0;i<k;i++){
            printf("%d ",tagx[j]);
        }
    }
    printf("\n");
    for(int j=0;j<4;j++){
        for(int i=0;i<k;i++){
            printf("%d ",ansx[j]+2*i);
        }
    }
    printf("\n");
    return 0;
}