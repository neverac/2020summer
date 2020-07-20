#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
int a,b,c,s;
set<unsigned short> q;
vector <unsigned short> v;
int ans[20];
int main(){
	cin>>a;
	while (a){
		cin>>b>>c>>s;
		for (int i=0;i<20;i++) ans[i]=-1;
		q.clear();
		v.clear();
		unsigned short tmp=s;
		while (q.find(tmp)==q.end()){
			q.insert(tmp);
			v.push_back(tmp);
			int x=tmp;
			int tt=(a*x+b)%c;
			tmp=(unsigned short)tt;	
		}
		unsigned short t1=v[0],t2=~v[0];
		for (int i=1;i<v.size();i++){
			t1=t1&v[i];
			t2=t2&(~v[i]);
		}
		unsigned short w=1;
		for (int i=0;i<16;i++){
			if (t1&w) ans[i]=1;
			w*=2;
		}
		w=1;
		for (int i=0;i<16;i++){
			if (t2&w) ans[i]=0;
			w*=2;
		}
		for (int i=15;i>=0;i--){
			if (ans[i]==-1) cout<<"?";else cout<<ans[i];
		}
		cout<<endl;
		cin>>a;
	}
	return 0;
} 

