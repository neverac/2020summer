#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
  ll a,b,ans = 0;
  scanf("%lld%lld",&a,&b);
  while(1){
    ans += a/b;
    if(!(a%b)) break;
    a %= b;
    swap(a,b);
  }
  printf("%lld",ans);
}