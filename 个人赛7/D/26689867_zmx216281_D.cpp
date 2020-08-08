#include<iostream>
#include<cstdio>
using namespace std;
long long a[10010];
long long getans(long long x){
    long long rec = 1;
    while(x%2==0)x/=2;
    for(int i=3;i<=7;i+=2){
        long long ex=1;
        long long num=1;
        while(x%i==0){
            x/=i;
            ex*=i;
            num+=ex;
        }
        rec=rec*num;
    }
    return rec;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",getans(a[i]));
    }
}