#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	long long a,b,ans=0;
	cin>>a>>b;
	while(b){
        ans+=a/b;
        a%=b;
        swap(a,b);
    }
    cout << ans << endl;
	return 0;
} 