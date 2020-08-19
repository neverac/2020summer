#include <bits/stdc++.h>
using namespace std;
long long n,m,gc,tot;
typedef long long ll;
ll gcd(ll a,ll b)//鏈€澶у叕绾︽暟锛岃緱杞浉闄?
{
	return b?gcd(b,a%b):a;
}
ll euler(ll nn){    
     ll res=nn,a=nn;  
     for(ll i=2;i*i<=a;i++){  
         if(a%i==0){  
             res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出   
             while(a%i==0) a/=i;  
         }  
     }  
     if(a>1) res=res/a*(a-1);  
    // cout<<res<<endl;
     return res;  
}  
int main(){
	int T;
	cin>>T;
	while (T--){
		tot=0;
		scanf("%lld%lld",&n,&m);
		gc=gcd(m,n);
		ll q=euler(m/gc);
		// for(int i=0;i<m;i++){
		// 	if(gcd(n+i,m)==gc){
		// 		printf("%d %lld\n",i,i+n);
		// 		tot++;
		// 	}
		// }
		printf("%lld\n",q);
	}
}