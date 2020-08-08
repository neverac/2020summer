#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int a[200050],recl[200050],recr[200050];
int main(){
    int n;
    int len=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        recl[i]=1;
    }
    for(int i=1;i<=n;i++){
        recr[i]=1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            recl[i]=recl[i-1]+1;
        }
        len=max(len,recl[i]);
    }
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1]){
            recr[i]=recr[i+1]+1;
        }
        len=max(len,recr[i]);
    }
    for(int i=1;i<=n-2;i++){
        if(a[i]<a[i+2]){
            len=max(len,recl[i]+recr[i+2]);
        }
    }
    cout<<len<<endl;
    return 0;
}