#include<stdio.h>
#include<iostream>
using namespace std;
int a;
int cx[10];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        cx[a]++;
    }
    
    if(cx[1]>=3)
    {
        printf("1 1 1");
        cx[1]-=3;
        while(cx[2]--)
        {
            printf(" 2");
        }
        while(cx[1]--)
        {
            printf(" 1");
        }
        printf("\n");
    }
    else
        if(cx[1]==2)
    {
        if(cx[2])
        {
            printf("2 1");
            cx[2]--;
            cx[1]--;
        
            while(cx[2]--)
            {
                printf(" 2");
            }
            printf(" 1\n");
        }
        else
            printf("1 1\n");
    }
    else
        if(cx[1]==1)
    {
        if(cx[2])
        {
            printf("2 1");
            cx[2]--;
            cx[1]--;
        
            while(cx[2]--)
            {
                printf(" 2");
            }
            printf("\n");
        }
        else
        {
            printf("1\n");
        }
    }
    else
    {
        while(cx[2]--)
        {
            printf("2 ");
        }
        printf("\n");
    }
        
    return 0;
    
}