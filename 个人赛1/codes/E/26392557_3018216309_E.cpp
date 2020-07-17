#include<cstdio>
#include<stack>
using namespace std;
long long n;

int main()
{
    while(~scanf("%lld",&n))
    {
        stack<char>p;
        while(n)
        {
            int t=n%26;

            if(n)
            {
            if(t==0)
            p.push('z');
            else
            p.push((char)('a'+t-1));
            }
            n/=26;
            if(!t)
            n--;
        }
        while(!p.empty())
        putchar(p.top()),p.pop();
        putchar('\n');
    }
    return 0;
}