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

int x[55];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>x[i];
    sort(x,x+n);
    int judge=0;
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                if(i!=j && j!=k && i!=k)
                {
                    if((x[i]-x[j])/x[k]*x[k] != (x[i]-x[j]))
                    {
                        judge=1;
                        break;
                    }
                }
            }
        }
    }

    if(judge==0)
        cout<<"yes"<<endl;
    else 
        cout<<"no"<<endl;

    
    
        

    //system("pause");
    return 0;
}