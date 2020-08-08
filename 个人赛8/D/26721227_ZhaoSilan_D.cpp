#include<stdio.h>
#include<iostream>
using namespace std;
int num[105];
int len[105];
char s[205];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            len[i]=max(num[i-1],num[i])+1;
        }
        len[n+1]=num[n]+1;
        
        for(int j=1;j<=len[1];j++)
        {
            s[j]=97+(j-1)%26;
            printf("%c",s[j]);
        }
        s[len[1]+1]=0;//结束符
        printf("\n");
        
        for(int i=2;i<=n+1;i++)
        {
            for(int j=1;j<=num[i-1];j++)
            {
                printf("%c",s[j]);//这里一定和之前的一样
            }
            
            if(s[num[i-1]+1])//如果前面一个字符串到这里还有的话
                s[num[i-1]+1]=(s[num[i-1]+1]-97+1)%26+97;//这个地方一定要修改的和之前不一样
            else
                s[num[i-1]+1]='a';//这个地方随便赋值一个
            
           // printf("%d\n",len[i]);
            if(len[i]>=num[i-1]+1)
            printf("%c",s[num[i-1]+1]);
            
            for(int j=num[i-1]+2;j<=len[i];j++)
            {
               s[j]=97+(j-1)%26;
               printf("%c",s[j]);
            }
            s[len[i]+1]=0;
            printf("\n");
        }
        
    }
    return 0;
}
