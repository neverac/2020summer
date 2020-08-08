#include <iostream>
using namespace std;
long long int A[15],ans=0,N,M;
long long int gcd(long long int a,long long int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
long long int lcm(long long int a,long long int b){
    return a*b/gcd(a,b);
}
long long int getnum(int cnt,int w,long long int pix){
    if(w>M||cnt<0){
        return 0;
    }
    if(cnt==0){
        return N/pix;
    }
    return getnum(cnt,w+1,pix)+getnum(cnt-1,w+1,lcm(pix,A[w]));
}
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%lld%lld",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%lld",A+i);
    }
    for(int i=1;i<=M;i++){
        if(i%2==1){
            ans+=getnum(i,0,1);
        }else{
            ans-=getnum(i,0,1);
        }
    }
    printf("%lld",ans);
    return 0;
}