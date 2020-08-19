#include <bits/stdc++.h>
using namespace std;
int a[30][220000];
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
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
        ++a[s[i]-'a'][i];
        for(int j=0;j<26;++j) a[j][i]+=a[j][i-1];
    }
	int n = read();
	for(int i=1;i<=n;++i){
        int l,r;
        cin>>l>>r;
        if(l==r) puts("Yes");
        else if(s[l-1]!=s[r-1]) puts("Yes");
        else{
        	int t = 0;
        	for(int j=0;j<26;++j){
            	int x = a[j][r-1];
            	int y = 0;
           	 	if(l>1) y=a[j][l-2];
            	if(x>y) ++t;
        	}
        	if(t>2) puts("Yes");
        	else puts("No");
        }
    }
}