#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        int num;scanf("%d",&num);
        if(num==1) cnt1++;
        if(num==2) cnt2++;
    }
    if(cnt2>0&&cnt1>0) printf("2 1 "),cnt2--,cnt1--;
    //else if(cnt1>2) printf("1 1 1 "),cnt1-=3;
    for(int i=0;i<cnt2;i++) printf("2 ");
    for(int i=0;i<cnt1;i++) printf("1 ");
    return 0;
}