#include<iostream>
using namespace std;
long long int a,b;
int main(){
	cin>>a>>b;
	if(a==b){
		cout<<1<<endl;
		return 0;
	}
	long long int ans=a/b,cur=0;
	a-=ans*b;
	while(1){
		if(a==1){
			ans+=b;
			break;
		}
		if(b==1){
			ans+=a;
			break;
		}
		cur+=(b/a);
		b%=a;
		swap(a,b);
	}
	cout<<ans+cur<<endl;
	return 0;
}
