#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
int main()
{
    string list;
    int res=0;
    cin>>list;
    
    
    res+=list[list.size()-1]-'0';
    res+=(list[list.size()-2]-'0')*10;
    cout<<(res%4==0?4:0)<<endl;
	return 0;
} 
