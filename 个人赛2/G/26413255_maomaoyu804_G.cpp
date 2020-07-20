#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt=0;int i=1;int num=n+1;int temp=0;
    while(temp<k/2){
        num=n+1-i;
    temp++;
        printf("%d %d ",i,n+1-i);
        i++;
        cnt+=2;
    }
    if(k%2==0)while(cnt<n) {printf("%d ",--num); cnt++;}
    else while(cnt<n) {printf("%d ",i++); cnt++;}
    return 0;
}