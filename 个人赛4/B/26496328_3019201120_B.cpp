#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;



const int N=1e5+10;
char str[N];

int res;
int m;
int sum;
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        sum=sum*10+str[i]-'0';
        sum=sum%4;
    }
    int res=str[len-1]-'0';
    if(res%2) m+=4;
    else m+=1;
    if(sum%4==2) m+=3;
    else if(sum%4==0) m+=2;
    m+=1;
    cout<<m%5<<endl;
    
    
    return 0;
}