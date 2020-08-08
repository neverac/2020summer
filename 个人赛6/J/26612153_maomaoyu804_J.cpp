#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d%d",&n,&k);
    int cnt=0;
    for(int i=0;i<n;i++){
        int num;scanf("%d",&num);
        cnt+=num/k;
        if(num%k!=0) cnt++;
    }
    printf("%d",(cnt+1)/2);
    return 0;
}