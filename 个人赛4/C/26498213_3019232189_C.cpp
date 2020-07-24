#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int T,n,x;
ll ans,mx,mn,fin;
char s[N];
int num[N*2];

int main(){
    ll now;
    scanf("%d",&T);
    while(T--){
        ans=0;
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&x);
        scanf("%s",s+1);
        mx=0; mn=0; fin=0;
        //++num[0+N];
        for(int i=1;i<=n;++i){
            if(s[i]=='0')
                ++fin;
            else
                --fin;
            ++num[fin+N];
            mx=max(mx,fin);
            mn=min(mn,fin);
        }
        if(fin==0){
            if(x>=mn&&x<=mx)
                ans=-1;
            else
                ans=0;
        }
        else{
            if(x>=mn&&x<=mx){
                if(x==0)
                    ++ans;
                now=0;
                while(x>=now+mn&&x<=now+mx){
                    ans+=num[x-now+N];
                    now+=fin;
                }
            }
            else{
                if(fin*x<0)
                    ans=0;
                else{
                    if(x==0)
                        ++ans;
                    now=x/fin*fin;
                    while(x>=now+mn&&x<=now+mx)
                        now-=fin;
                    while(!(x>=now+mn&&x<=now+mx))
                        now+=fin;
                    while(x>=now+mn&&x<=now+mx){
                        ans+=num[x-now+N];
                        now+=fin;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }

    //while(1);
}
