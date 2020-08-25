#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int T,fla,t1,t2,tot;
int c[16];

int main(){
    scanf("%d",&T);
    while(T--){
        fla=0;
        tot=0;
        for(int i=0;i<10;++i){
            scanf("%d",&c[i]);
            tot+=c[i];
        }
        for(int k=0;k<10;++k)
            if(c[k]){
                --c[k];
                for(int j=0;j<=k;++j){
                    if(c[j]&&(k*10+j)%4==0){
                        fla=1;
                        t1=k; t2=j;
                        break;
                    }
                    if(c[j]&&(j*10+k)%4==0){
                        fla=1;
                        t1=j; t2=k;
                        break;
                    }
                }
                ++c[k];
                if(fla)
                    break;
            }
        
        if(fla){
            if(t1==0&&tot==c[0])
                printf("0\n");
            else{
                --c[t1];
                --c[t2];
                for(int i=9;i>=0;--i)
                    for(int j=1;j<=c[i];++j)
                        printf("%d",i);
                printf("%d%d\n",t1,t2);
            }
        }
        else{
            if(c[8])
                printf("8\n");
            else if(c[4])
                printf("4\n");
            else if(c[0])
                printf("0\n");
            else
                printf("-1\n");
        }
    }
   // while(1);
}
/*
10
1 1 1 0 0 0 0 0 0 0 
0 1 0 0 0 0 0 0 0 0 
0 0 1 0 0 0 0 0 1 0 
0 0 0 1 0 0 0 0 0 0 
0 0 0 0 1 0 1 0 0 0 
0 0 0 0 0 1 0 0 0 0 
0 0 0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 0 1 0 
0 0 0 0 0 0 0 0 0 1 
*/
