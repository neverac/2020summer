#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long rec = 0;
    int temp;
    for(int i =0; i < n; i ++)
    {
        cin>>temp;
        rec += (temp + k -1)/k;
    }
    if(rec % 2 == 0){
        cout<<rec/2<<endl;
    }else{
        cout<<rec/2+1<<endl;
    }
    return 0;
}
