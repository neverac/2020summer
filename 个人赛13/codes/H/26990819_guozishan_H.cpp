#include <iostream>
#include <cstdio>
#define mod 998244353
using namespace std;
long long rec[510][510];
long long last[510][510];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    //cout<<n<<m<<k;
    long long temp = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1;j <= m; j ++)
        {
            scanf("%lld",&temp);
            rec[i][j] = temp%mod;
            //cout<<temp<<endl;
        }
    }
    char ch;
    int num;
    long long t,res = 0;
    while(k--)
    {
        cin>>ch;
        scanf("%d %lld",&num,&t);
        //cout<<ch<<num<<t<<endl;
        if(ch == 'r')
        {
            for(int i = 1; i <= m; i++)
            {
                //cout<<i<<endl;
                long long rt = (t - last[num][i])%mod;
                res = (res + rec[num][i]*rt)%mod;
                last[num][i] = t;
            }
        }
        if(ch == 'c')
        {
            for(int i = 1; i <= n; i++)
            {
                long long rt = (t - last[i][num])%mod;
                res = (res + rec[i][num]*rt)%mod;
                last[i][num] = t;
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
