#include <iostream>

using namespace std;
typedef long long ll;
ll res;
ll temp;
int main()
{
    ll a,b;
    cin>>a>>b;
    while((a!=1)&&(b!=1))
    {
        res+=a/b;
        a=a%b;
        swap(a,b);
    }
    if(a==1)
    {
        res+=b;
    }
    else if(b==1)
    {
        res+=a;
    }
    cout<<res<<endl;
}