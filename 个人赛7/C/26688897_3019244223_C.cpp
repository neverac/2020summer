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


int main()
{  
    int n;
    cin>>n;
    queue<int> s;
    queue<int> q;
    int a;
    int x,y;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        s.push(a);
    }
    for(int i=0;i<n;++i)
    {
        cin>>a;
        q.push(a);
    }
    while( !s.empty() || !q.empty() )
    {
        if(s.empty())
        {
            cout<<q.size()<<endl;
            break;
        }
        else if(q.empty())
        {
            cout<<s.size()<<endl;
            break;
        }
        x=s.front();
        y=q.front();
        if(x>y)
            q.pop();
        else 
            s.pop();
    }





 
    //system("pause");
    return 0;
}

