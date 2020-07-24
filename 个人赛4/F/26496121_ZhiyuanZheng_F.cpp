#include <bits/stdc++.h>
using namespace std;
int k,n,s,p;

int main(){
	cin>>k>>n>>s>>p;
	int x=n/s;
	if (x*s!=n) x++;
	x*=k;
	int qq=x/p;
	if (qq*p!=x)qq++;
	cout <<qq<<endl;
	return 0; 
}

