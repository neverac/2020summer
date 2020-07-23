#include<iostream>
using namespace std;
int main(){
  int n;
	char c;
	int ans = 0;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>c;
		if(c=='-'&&ans>=1) ans--;
		else if(c =='+') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
