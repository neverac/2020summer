#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int c;
    cin>>c;
    while(c--){
        int n,k;
        cin>>n>>k;
        //算他在哪一段：q = k/(n-1)+1;
        //减去之前的数字：p = k-(n-1)*(q-1)
        //这一段开始的数字：n*（q-1）
        //加上:p+n*（q-1）;
        long long  q = k/(n-1) +1;
        long long p = k-(n-1)*(q-1);
        long long beg = n*(q-1);
        long long res = p + beg;
        if(p != 0){
        cout<<res<<endl;
        }else{
        cout<<res-1<<endl;
        }
    }
    return 0;
}
