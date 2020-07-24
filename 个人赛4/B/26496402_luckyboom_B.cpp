#include<bits/stdc++.h>
using namespace std;
int len;
string s;
long long mypow(int x,int y){
    if(y==0)return 1;
    long long ans=1;
    while(y){
        ans*=x;y--;
    }
    return ans;
}
void work(){
    if(len==1){
        int i=s[0]-'0';
        printf("%lld\n",(1+mypow(2,i)+mypow(3,i)+mypow(4,i))%5);
    }
    else{
        int g,i=(s[len-2]-'0')*10+s[len-1]-'0';
        g=i%4;
        printf("%lld\n",(1+mypow(2,g)+mypow(3,g)+mypow(4,g))%5);
    }
}
long long  pow_fast(long  a,long  b){
	long long  num=1;
	for(;b;b>>=1,a=a*a)
	  if(b&1)num=num*a;
	return num;
}
int main(){
    
    cin>>s;
    len=s.length();
    work();
    return 0;
}