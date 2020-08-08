#include <iostream>

using namespace std;

long long solve(long long num, int b)
{
    long long res = 1;
    long long temp = 1;
    while(num % b == 0)
    {
        num /= b;
        temp *= b;
        res += temp;
    }
    return res;
}


int main()
{
    int N;
    long long a;
    cin>>N;
    while(N--)
    {
        cin>>a;
        while (a % 2 == 0)
        {
            a  /= 2;
        }
        long long res1 = solve(a,3);
        long long res2 = solve(a,5);
        long long res3 = solve(a,7);
        cout<<res1*res2*res3<<endl;
    }
    return 0;
}
