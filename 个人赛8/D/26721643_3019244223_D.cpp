#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long  ll;
int x[105];
string s[105];
int main()
{  
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int max_len=0;
        for(int i=0;i<n;++i)
        {
            cin>>x[i];
            max_len=max(max_len,x[i]);
            s[i]="";
        } 
        max_len=max(max_len,1);
        string start="";
        for(int i=0;i<max_len;++i)
        {
            start+='a';
            for(int j=0;j<n;++j)
                s[j]+='a';
        }
        cout<<start<<endl;
        s[0][x[0]]='b';
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<x[i];++j)
                s[i][j] = s[i-1][j];

            if(s[i-1][x[i]]=='z')
                s[i][x[i]] ='a';
            else 
                s[i][x[i]] = char(s[i-1][x[i]]+1);
        }
        for(int i=0;i<n;++i)
            cout<<s[i]<<endl;
    }



    //system("pause");
    return 0;
}

