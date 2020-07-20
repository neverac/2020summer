#include <iostream>

using namespace std;
int res[100002];

int main()
{
    int n,k;
    cin>>n>>k;
    res[0] = 1;
    int dizeng = n-1,rec = 1;
    cout<<res[0]<<" ";
    for(int i = 1; i < k; i++){
        res[i] = res[i-1] + rec*dizeng;
        dizeng--;
        rec = -rec;
        cout<<res[i]<<" ";
    }
    int temp = res[k-1];
    //cout<<":::"<<k%2<<endl;
    if(k%2==0){
        temp--;
       // cout<<temp<<endl;
       for(int i = k ; i < n-1 ; i++){
            cout<<temp<<" ";
            temp--;
       }
       cout<<temp<<endl;
    }else{
        temp++;
      //  cout<<temp<<endl;
        for(int i = k ; i < n-1 ; i++){
            cout<<temp<<" ";
            temp++;
       }
       cout<<temp<<endl;
    }
    return 0;
}
