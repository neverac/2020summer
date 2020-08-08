#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    int i=1,j=1;
    while(i<=n&&j<=n){
        if(a[i]<b[j]) i++;
        else j++;
    }
    if(j<=n) printf("%d",n-j+1);
    else printf("%d",n-i+1);
    return 0;
}