#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n,m;

int f[3000];
int numm[3000];

int getf(int x)
{
    if(f[x] == x) return x;
    else return f[x] = getf(f[x]);
}


void merge(int x,int y)
{
    int a = getf(x);
    int b = getf(y);
    if(a != b) f[b] = a;
}

int main()
{
    scanf("%d%d",&n,&m);
    long long int num=n*m;
    for(int i = 0;i <num;i++)
    {
        f[i] = i;//先把每个人的爸爸都赋值为自己
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int nn;
            scanf("%d",&nn);
            if((nn&1)==0)
            {
                if(j!=0)
                {
                    merge(i*m+j,i*m+j-1);
                }
            }
            nn>>=1;
            if((nn&1)==0)
            {
                if(i!=0)
                {
                    merge(i*m+j,(i-1)*m+j);
                }
            }
            nn>>=1;
            if((nn&1)==0)
            {
                if(j!=m-1)
                {
                    merge(i*m+j,i*m+j+1);
                }
            }
            nn>>=1;
            if((nn&1)==0)
            {
                if(i!=n-1)
                {
                    merge(i*m+j,(i+1)*m+j);
                }
            }
        }
    int numh=0;
    int maxl=0;
    for(int i = 0;i < num;i++)
    {
        int pp=getf(i);
        if(numm[pp]==0)
        {
            numh++;
        }
        numm[pp]++;
        if(numm[pp]>maxl)
        {
            maxl=numm[pp];
        }
    }
    
    printf("%d\n%d\n",numh,maxl);
    return 0;
}