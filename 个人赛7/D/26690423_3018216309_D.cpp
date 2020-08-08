#include <bits/stdc++.h>
const int N =10010;
using namespace std;
long long a[N];
long long find(long long x){
    while(x%2==0) x/=2;
    long long r=1;
    for(int i=3;i<=7;i+=2){
        long long t=1;
        long long sum=1;
        int num=0;
        while(x%i==0){
            num++;
            x/=i;
            t*=i;
            sum+=t;
        }
        r=r*sum;
    }
    return r;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++) 
    {
        printf("%lld\n",find(a[i]));
        
    }
    return 0;
}
