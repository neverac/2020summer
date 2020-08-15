#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
#define scan(n) scanf("%d",&n)

struct per
{
  int r,c;//原位置
  int d;//原位置离出口的距离
};
struct per pe[500005];

bool cmp(struct per a,struct per b)
{
    return a.d>b.d;
}

int main()
{
    int r,s,p,i;
    cin>>r>>s>>p;
    for(i=0;i<p;i++)
    {
        cin>>pe[i].r>>pe[i].c;
        if(pe[i].c>s)
            pe[i].d=(pe[i].c-s)+(r-pe[i].r+1);
        else
            pe[i].d=(s-pe[i].c+1)+(r-pe[i].r+1);
    }
    sort(pe,pe+p,cmp);
    int k=1;//在队列中等待进入车厢的时间
    int maxtime=pe[0].d;
    for(i=1;i<p;i++)
    {
        if(pe[i].d+k>maxtime)
            maxtime=pe[i].d+k;
        k++;
    }
    cout<<maxtime<<endl;
    return 0;
}