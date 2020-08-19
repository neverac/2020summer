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
using namespace std;
#define ll  long long
#define ull unsigned long long

struct qwq
{
    int s;
    int k;
};
qwq a[105];
qwq r[105];
bool cmp(qwq q,qwq w)
{
    if(q.k==w.k)
        return q.s<w.s;
    return q.k>w.k;
}
bool cmmp(qwq q,qwq w)
{
    return q.s<w.s;
}
int main()
{  
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int m;
        cin>>m;
        a[i].s=i;
        a[i].k=m;
    }
    sort(a+1,a+1+n,cmp);
    int t;
    cin>>t;
    int l,p;
    for(int i=0;i<t;++i)
    {
        cin>>l>>p;
        for(int j=1;j<=l;++j)
            r[j]=a[j];
        sort(r+1,r+l+1,cmmp);
        cout<<r[p].k<<endl;
    }





    //system("pause");
    return 0;
}

