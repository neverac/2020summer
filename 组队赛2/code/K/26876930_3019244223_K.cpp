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
#include<cctype>
using namespace std;
#define ll  long long
#define ull unsigned long long
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

struct qwq
{
    
};
bool cmp(qwq q,qwq w)
{
    
}

ll x[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll sum=0;
        priority_queue <int,vector<int>,greater<int> > pq;
        for(int i=0;i<n;++i)
        {
            int a;
            cin>>a;
            pq.push(a);
        }
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            sum=sum+a+b;
            pq.push(a+b);
            //cout<<a<<" "<<b<<endl;
        }
        //sum+=pq.top();
        cout<<sum<<endl;

    }

    
    
        

   // system("pause");
    return 0;
}