#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<memory.h>
using namespace std;
vector<int>v[30];
char s[100005];
bool vis[30];
int main()
{
    long long int k;
    scanf("%lld",&k);
    scanf("%s",s+1);
    long long int len=strlen(s+1);
    for(int i=1;s[i];i++)
    {
        v[s[i]-97].push_back(i);
    }
    long long int ans=0;
    for(int i=1;s[i];i++)
    {
        long long int l,r;
        long long int tt=lower_bound(v[s[i]-97].begin(),v[s[i]-97].end(),i)-v[s[i]-97].begin();
        long long int pp;
//        printf("%d %d\n",i,tt);
        if(vis[s[i]-97])//如果这个字母用过了，那么所有的包含前面字母的这个贡献度已经计算过了，只能算没有包含之前字幕的
        {
               pp=1;
        }
        else
        {
            pp=k;
            vis[s[i]-97]=1;
        }
        
        if(tt-pp<0)
        {
            l=0;
        }
        else
            l=v[s[i]-97][tt-pp];
        
        if(tt+k>=v[s[i]-97].size())
        {
            r=len+1;
        }
        else
            r=v[s[i]-97][tt+k];
        
        
        ans+=(i-l)*(r-i);
//        printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}
