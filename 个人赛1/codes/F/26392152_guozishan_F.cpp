#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int res[100005] = {0};
int N,d = 0;
long long sum = 0;
int main()
{

     while(~scanf("%d",&N))
    {
     sum = 0;
     memset(res,0,sizeof(res));
     for(int i = 0; i < N; i++)
     {
        scanf("%d",&d);
        res[d] ++;
        sum+= d;
     }
     int Q;
     scanf("%d",&Q);
     int y=0,x=0;
     for(int i = 0; i < Q; i++){
        scanf("%d %d",&y,&x);
        sum += (x-y)*res[y];
        res[x] += res[y];
        res[y] = 0;
        cout<<sum<<endl;
     }
     }
    return 0;
}
