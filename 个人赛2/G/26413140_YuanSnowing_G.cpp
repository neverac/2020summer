#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,k,tmp,f,tmp2;
int main(){
	cin >> n >> k;
	cout << 1 <<" ";
	tmp = n;
	tmp2 = 2;
	n --;
	f = 0;
	k --;
	while(k --){
		if(!f) {
			cout << tmp;
			tmp --;
		}
		else {
			cout << tmp2;
			tmp2 ++;
		}
		n --;
		f = !f;
		if(n == 0) cout << endl;
		else cout << " ";
	}
	if(!f){
		for(int i = tmp2;i <= tmp; ++ i){
			cout << i;
			n --;
			if(n == 0) cout << endl;
			else cout << " ";
		}
	}
	else{
		for(int i = tmp;i >= tmp2; -- i){
			cout << i;
			n --;
			if(n == 0) cout << endl;
			else cout << " ";
		}
	}
	
    return 0;
}