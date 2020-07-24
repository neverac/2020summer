#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
char s[100005];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    if(len==1)
    {
        int x=s[len-1]-48;
        if(x%4==0)
        {
                printf("4\n");
        }
        else
        {
                printf("0\n");
        }
        return 0;
    }
    
    int x=(s[len-2]-48)*10+s[len-1]-48;
    if(x%4==0)
    {
            printf("4\n");
    }
    else
    {
            printf("0\n");
    }
return 0;
    
}
