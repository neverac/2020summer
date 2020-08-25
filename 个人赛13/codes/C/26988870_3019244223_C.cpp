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
#include<set>
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
bool cmp(string q,string w)
{
    return q.size()<w.size();
}


set<string> ss;
int x[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    string a;
    for(int i=0;i<m;++i)
    {
        cin>>a;
        ss.insert(a);
    }

    int num=0;
    for (set<string>::iterator it=ss.begin() ;it!=ss.end();it++)
        x[++num] = (*it).size();

    sort(x+1,x+1+num);
    int sum=0;
    for(int i=1;i<=num;++i)
    {
        if(n>=x[i])
        {
            sum++;
            n-=x[i];
            n--;
        }
    }
    cout<<sum<<endl;



    
    
        

    //system("pause");
    return 0;
}