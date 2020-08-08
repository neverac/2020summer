#include <bits/stdc++.h>
using namespace std;
int d;
long long a[370];
int main(){
	cin>>d;
	for (int i=1;i<=d;i++){
		cin>>a[i];
	}
	long long ori=100,p=0;
	bool ok=true;
	long long num=600;
	for (int i=1;i<=d;i++){
		if (ok){
			if (num>=a[i]) num=a[i];
			else {
				ok=!ok;
				p=ori/num;
				if (p>100000) p=100000;
				ori-=p*num;
				num=a[i];
			}
		}else {
			if (num<=a[i]) num=a[i];
			else{
				ok=!ok;
				ori+=p*num;
				p=0;
				num=a[i];
			}
		}
//		cout<<i<<" "<<ori<<" "<<p<<endl; 
	}
	if (p!=0){
		ori+=p*a[d];
	}
	cout<<ori<<endl;
	return 0;
}

