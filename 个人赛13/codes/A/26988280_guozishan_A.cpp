#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m,x,y;
        cin>>n>>m>>x>>y;
        if(x <= y)
        {
            cout<<m<<endl;
        }else
        {
            long long res = (n+(m-1)*y)/x;
            if(res > m)
            {
                res = m;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
