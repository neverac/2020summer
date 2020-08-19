#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int T;
long long a,b;
long long prime[100];
int m;

long long gcd(long long a,long long b)
{
    if(a<b){
        swap(a,b);
    }
    while(a%b!=0){
        long long temp=a%b;
        a=b;
        b=temp;
    }
    return b;
}

void get_prime(long long n)
{
    memset(prime,0,sizeof(prime));
    for(long long i=2;i*i<=n;i++){
        if(n && n%i==0){
            prime[m++]=i;
            while(n && n%i==0)
                n/=i;
        }
    }
    if(n>1)
        prime[m++]=n;
}

long long solve(long long num)
{
    long long i,j;
    long long ans=0,tmp,flag;
    for(i=1;i<1<<m;i++){
        tmp=1,flag=0;
        for(j=0;j<m;j++){
            if(i&1<<j)
                flag++,tmp*=prime[j];
        }
        if(flag&1)
            ans+=num/tmp;
        else
            ans-=num/tmp;
    }
    return ans;
}

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&a,&b);
        long long r=gcd(a,b);
        long long k1=a/r,k2=b/r;
        m=0;
        get_prime(k2);
        long long h=k2;
        long long x=k1,y=k1+h-1;
        printf("%I64d\n",y-solve(y)-(x-1-solve(x-1)));
    }
    return 0;
}
