#include<stdio.h>
#include<iostream>
using namespace std;
char s[300005];
int a[300005],b[300005],c[300005];
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s",s);
        int num1=0;
        int num2=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]&1)
            {
                a[num1++]=s[i]-48;
            }
            else
            {
                b[num2++]=s[i]-48;
            }
        }
//        printf("%d %d\n",num1,num2);
        int i=0,j=0,k=0;
        while(i<num1&&j<num2)
        {
            if(a[i]<b[j])
            {
                c[k++]=a[i];
                i++;
            }
            else
            {
                c[k++]=b[j];
                j++;
            }
        }
//        printf("%d %d\n",i,j);
        while(i<num1)
        {
            c[k++]=a[i++];
        }
        
        while(j<num2)
        {
            c[k++]=b[j++];
        }
        
        for(int i=0;i<k;i++)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}
