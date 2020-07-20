#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=25;
string s;
int len;
long long getint(int x,int y){
	long long ans=0;
	for(int i=x;i<=y;i++){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
long long  work(){
	long long ans=getint(0,0)+getint(1,1)-getint(2,2)*getint(3,3)/getint(4,len-1);
	for(int i=1;i<=3;i++){
		if(i+2>len)continue;
		ll jian=getint(len-i-2,len-i-2)*getint(len-i-1,len-i-1)/getint(len-i,len-1),jia1,jia2;
		for(int j=1;j<=2;j++){
			if(j+3+i>len)continue;
			jia1=getint(0,0+j-1)+getint(0+j,len-i-3);
			jia2=getint(len-i-2-j,len-i-3)+getint(0,len-i-3-j);
			//cout<<"haha1"<<jia1-jian<<endl;
			//cout<<"haha1"<<jia2-jian<<endl;
			
			ans=max(ans,jia1-jian);
			ans=max(ans,jia2-jian);
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	
	for(int q=1;q<=t;q++){
		cin>>s;
		len=s.length();

		printf("Case #%d: %lld\n",q,work())	;
	}
	
	return 0;
}