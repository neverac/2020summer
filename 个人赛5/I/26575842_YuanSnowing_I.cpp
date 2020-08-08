#include <bits/stdc++.h>
using namespace std;
const int N=3*1e5+10;
int T,len,ji[N],ou[N];
string s;
int main(){
    cin >> T;
    while(T --){
    	cin >> s;
    	len = s.length();
    	int cj=0,co=0;
    	for(int i = 0,tmp;i < len; ++ i){
    		tmp = s[i]-'0';
    		if(tmp%2) ji[cj ++] = tmp;
    		else ou[co ++] = tmp;
    	}
    	int o=0,j=0;
    	while(len --){
    		if(co == o) printf("%d",ji[j ++]);
    		else if(cj == j) printf("%d",ou[o ++]);
    		else if(ji[j] < ou[o]) printf("%d",ji[j ++]);
    		else printf("%d",ou[o ++]);
    	}
    	printf("\n");
    }
    return 0;
} 