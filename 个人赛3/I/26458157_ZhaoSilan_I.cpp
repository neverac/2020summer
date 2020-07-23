#include<stdio.h>
#include<iostream>
using namespace std;
char s[105];
int main()
{
    int n;
    scanf("%d\n",&n);
    scanf("%s",s);
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='-')
        {
            if(num)
                num--;
        }
        else
        {
            num++;
        }
    }
    printf("%d\n",num);
    return 0;
}
