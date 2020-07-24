#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string n;
    cin>>n;
    int num;
    long long int len=n.length();
    if(len>=2){
    num=n[len-1]-'0'+(n[len-2]-'0')*10;
    }
    else num=n[len-1]-'0';
    if(num%4==0){
        cout<<4<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
