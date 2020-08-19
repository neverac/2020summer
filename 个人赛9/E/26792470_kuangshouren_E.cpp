#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
long long phi(long long n)
{
    long long res=n;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            res=res-res/i;
            do{
                n/=i;
            }while(n%i==0);
        }
    }
    if(n>1) res=res-res/n;
    return res;
}
int main()
{
	int T;
	cin>>T;
	for(int w=1;w<=T;++w)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long z=gcd(x,y);
		x/=z;y/=z;
		cout<<phi(y)<<endl;
	}
	return 0;
}