#include <iostream>

using namespace std;
int t;
long long a,mm,a1,m1;
long long gcd(long long a,long long m)
{
    if(m==0)
    {
        return a;
    }
    else return gcd(m,a%m);
}
long long eular(long long n)
{
    long long ans = n;
    for(long long int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
int main()
{
    cin>>t;
    while(t--)
    {   cin>>a>>mm;
        a1=a/gcd(a,mm);
        m1=mm/gcd(a,mm);
        cout<<eular(m1)<<endl;
    }
    return 0;
}
