#include<iostream>
#include<algorithm>
using namespace std;
long  a[100010];
long  cont[100010]={};
int main(){
    long long n,q,x,y;
    while(~scanf("%lld",&n)){
        long long total=0;  
        for(int i=0;i<n;i++){
            scanf("%ld",&a[i]);
            cont[a[i]]++;
            total+=a[i];
        }
        scanf("%lld",&q);
        for(int i=0;i<q;i++){
            scanf("%lld %lld",&x,&y);
            total += (cont[x])*(y-x);
            cont[y]+=cont[x];
            cont[x]=0;
            cout << total << endl;
        } 
    }
    
}