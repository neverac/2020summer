#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int c[10];
string s[25]={"00","04","08","12","16","20",
			"24","28","32","36","40",
			"44","48","52","56","60",
			"64","68","72","76","80",
			"84","88","92","96"};
vector <string> v;
bool cmp(string x,string y){
	if (x.size()==y.size()) return x>y;
	return x.size()>y.size();
}
int main(){
	IO;
	int T;
	cin>>T;
	while (T--){
		v.clear();
		memset(c,0,sizeof c);
		for (int i=0;i<=9;i++){
			cin>>c[i];
		}
		
		if (c[0]) v.push_back("0");
		if (c[4]) v.push_back("4");
		if (c[8]) v.push_back("8");
		
		for (int i=0;i<25;i++){
			int x1=s[i][0]-'0',x2=s[i][1]-'0';
			if ((x1==x2&&c[x1]>=2)||(x1!=x2&&c[x1]&&c[x2])){
				c[x1]--;c[x2]--;
				string ss="";
				for (int j=9;j>=0;j--){
					if (j==0&&ss=="") break;
					for (int k=1;k<=c[j];k++){
						ss+=(char)(j+'0');
					}
				}
				ss+=s[i];
				v.push_back(ss);
				c[x1]++;c[x2]++;
			}
		}
		sort(v.begin(),v.end(),cmp);
		if (v.size()==0) cout<<-1<<endl;else {
			int i=0,l=v[0].size();
			while (v[0][i]=='0'&&i<l) i++;
			if (i==l) i--;
			for (int now=i;now<l;now++) cout<<v[0][now];
			cout<<endl;
		}
	}
	return 0;
}

