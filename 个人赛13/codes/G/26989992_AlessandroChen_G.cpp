#pragma GCC optimize(2)
    #include<bits/stdc++.h>
    #define ll long long
    #define maxn 1005
    #define inf 1e9
    #define pb push_back
    #define fi first
    #define se second
    #define rep(i,a,b) for(int i=a;i<=b;i++)
    #define per(i,a,b) for(int i=a;i>=b;i--)
    using namespace std;
    const ll mod=998244353;
    stack<pair<ll, ll> > sta;
    inline ll read()
    {
    	ll x=0,w=1; char c=getchar();
    	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
    	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
    	return w==1?x:-x;
    }
    const int N=1e7+10;
    ll n,p,x,y,z,b;
     
    int main()
    {
        n=read(),p=read(),x=read(),y=read(),z=read(),b=read();
        ll now=0,ans=0,sum=0;
        for(int i=1;i<=n;++i){
            ll len=1;
            while(sta.size()&&sta.top().first>=b){
                len+=sta.top().second;
                now=(now-sta.top().first*sta.top().second%mod+mod)%mod;
                sta.pop();
            }
            sta.push(make_pair(b,len));
            now=(now+b*len%mod)%mod;
     
            sum=(sum+now)%mod;
            ans=ans^sum;
            b=(x*sum%p+y*b%p+z)%p;
        }
        printf("%lld\n",ans);
    }