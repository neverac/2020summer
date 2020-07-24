#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    char x;
    int ans=0;
    while(scanf("%c",&x)==1){
        if(x<'0'||x>'9'){
            break;
        }
        ans=(10*ans+x-'0')%4;
    }
    if(ans==0){
        printf("4");
    }else{
        printf("0");
    }
    return 0;
}