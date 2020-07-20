#include <iostream>
using namespace std;
int list[2]={-1,1};
int list2[100010]={1};
int main(){
    int a, b;
    cin >> a >> b;
    int c = b;
    printf("1 ");
    for(int i = 1 ; i<=c ; i++ , b-- ){
        list2[i]=list2[i-1]+list[i%2]*b;
        printf("%d ",list2[i]);
    }
    int d = c+2;
    for(int i = c+1 ; i < a ; i++,d++){
        printf("%d ",d);
    }
    return 0;
}