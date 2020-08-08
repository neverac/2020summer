#include<cstdio>
#include<iostream>
using namespace std;
int a[105];
int b[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int i=0,j=0;
    while(i<n&&j<n){
        if(a[i]<b[j])i++;
        else{
            j++;
        }
    }
    cout << 2*n-j-i << endl;
}