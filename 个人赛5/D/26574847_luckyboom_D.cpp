#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
void work(){
    int m=n-1,g,l;
    if(!(k%(n-1))){
        printf("%d\n",k/(n-1)*n-1);
        return ;
    }
    l=k/(n-1);
    g=k/(n-1)*n;
    printf("%d\n",g+k-(n-1)*l);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        work();
    }
    return 0;
}