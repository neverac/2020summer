#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int cnt = m+1;
        bitset<1000> number[30];
        for (int i = 1;i <= m; ++i){
        	string s;
            cin>>s;
            number[i-1] = bitset<1000>(s);
        }
        int len = 1<<m;
        for(int i = 1; i < len; ++i){
            int k = i, p = 0;
            bitset<1000> tmp(0);
            for(int j = 0; j < m; ++j){
                if(k & 1){
                	++p;
					tmp |= number[j]; 
				}
                k /= 2;
                if(!k) break;
            }
            if (tmp.count() == n) cnt = min(cnt,p);
        }
        if(cnt <= m) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
}