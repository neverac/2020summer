#include<bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> > q;
long long int ans=0;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        ans=0;
        scanf("%d",&n);
        while(!q.empty())
        {
            q.pop();
        }
        for(int i=0;i<n;i++)
        {
            long long int x;
            scanf("%lld",&x);
            q.push(x);
        }
        if(n==1)
        {
            printf("%lld\n",q.top());
            continue;
        }
        for(int i=1;i<n;i++)
        {
            long long int a=q.top();
            q.pop();
            long long int b=q.top();
            q.pop();
            ans+=a+b;
//            printf("%lld\n",ans);
            q.push(a+b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
