#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 400006
using namespace std;

int n;
int num[3];

int main(){
    int temp,now,t1,t2;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&temp);
        ++num[temp];
    }
    if(num[2]>=1){
        printf("2 ");
        --num[2];
        if(num[1]>=1){
            printf("1 ");
            --num[1];
        }
        for(int i=1;i<=num[2];++i)
            printf("2 ");
        for(int i=1;i<=num[1];++i)
            printf("1 ");
    }
    else{
        for(int i=1;i<=num[1];++i)
            printf("1 ");
    }

    //while(1);
}
