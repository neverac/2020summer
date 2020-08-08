#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
	int T;
	T = read();
	while(T--){
		queue <int> num1;
		queue <int> num2;
		while (!num1.empty()) num1.pop();
		while (!num2.empty()) num2.pop();
		string s;
		cin>>s;
		int n = s.size();
		for(int i = 0; i < n;++i){
			int k = s[i] - '0';
			if(k%2==1) num1.push(k);
			if(k%2==0) num2.push(k);
		}
		while(!num1.empty() && !num2.empty()){
			if(num1.front() > num2.front()) {printf("%d",num2.front());num2.pop();}
			else {printf("%d",num1.front());num1.pop();}
		}
		if(num1.empty()) {
			while(!num2.empty()){printf("%d",num2.front());num2.pop();}
		}
		else{
			while(!num1.empty()){printf("%d",num1.front());num1.pop();}
		}
		printf("\n");
	}
	return 0;
}