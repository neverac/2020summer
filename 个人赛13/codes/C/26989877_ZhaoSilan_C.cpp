#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
string s;
map<string,int>qq;
long long int p[1005];
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    int num=0;
    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(qq.count(s))
            continue;
        qq[s]=1;
        p[num++]=s.length();
    }
    sort(p,p+num);
    int ans=0,pp=-1;
    for(int i=0;i<num;i++)
    {
        //printf("%d ",p[i]);
        if(pp+p[i]+1>n)
            break;
        pp+=p[i]+1;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
