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
using namespace std;
int main()
{  
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        queue<char> j;
        queue<char> o;
        for(int i=0;i<s.size();++i)
        {
            if( (s[i]-'0')%2==0)
                o.push(s[i]);
            else 
                j.push(s[i]);
        }
        string ans="";
        while(!o.empty() || !j.empty())
        {
            if(o.empty() && !j.empty())
            {
                ans+=j.front();
                j.pop();
            }
            else if(j.empty() && !o.empty())
            {
                ans+=o.front();
                o.pop();
            }
            else 
            {
                char x,y;
                x=o.front();
                y=j.front();
                if(x<y)
                {
                    ans+=o.front();
                    o.pop();
                }
                else 
                {
                    ans+=j.front();
                    j.pop();
                }
            }
        }
        cout<<ans<<endl;
    }

   
    //system("pause");
    return 0;
}