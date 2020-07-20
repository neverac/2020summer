#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int n,k;

int main(){
    scanf("%d%d",&n,&k);
    int l=0,r=1+k+1,fla=1;
    while(l<r){
        if(fla){
            ++l;
            if(l<r)
                printf("%d ",l);
        }
        else{
            --r;
            if(l<r)
                printf("%d ",r);
        }
        fla^=1;
    }
    for(int i=2+k;i<=n;++i)
        printf("%d ",i);
    cout<<'\n';

    //while(1);
}
