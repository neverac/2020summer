#include<bits/stdc++.h>
using namespace std;
long long s[1020],k;
 int Euler(int n){    
     int res=n,a=n;  
     for(int i=2;i*i<=a;i++){  
         if(a%i==0)
         {  
             res=res/i*(i-1);//要先进行除法,防止中间数据的溢出   
             while(a%i==0) a/=i;  
         }  
     }  
     if(a>1) res=res/a*(a-1);  
     return res;  
}
void prime(long long m)//求一个数的素因子
{
    long long i;
       k=0;
    for(i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            s[k++]=i;
            while(m%i==0)
                m/=i;
//printf("%d\n",m);
        }
    }
        if(m>1)
            s[k++]=m;
 
            //printf("###\n");
}
long long quc(long long m)//队列数组实现容斥原理
{
  long long p[10020],i,j,t=0,sum=0,z;
    p[t++]=-1;
    for(i=0;i<k;i++)
    {
        z=t;
        for(j=0;j<z;j++)
        {
            p[t++]=p[j]*s[i]*(-1);
        }
    }
    for(i=1;i<t;i++)
        sum+=m/p[i];
    return sum;
}
int main(){
	int T;
	cin>>T;
	while (T--){
		k=0;
		memset(s,0,sizeof s);
		long long a,m;
		cin>>a>>m;
		long long tmp=__gcd(a,m);
		a/=tmp;
		m/=tmp;
		prime(m);
		long long num=a+m-quc(a+m)-(a-1)+quc(a-1);
		cout<<num-1ll<<endl;
	}
		
	
}