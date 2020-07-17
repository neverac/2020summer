#include <iostream>
#include <string>
using namespace std;
string s="";
int main(){
    unsigned long long int N;
    cin>>N;
    while(N){
        s=(char)('a'+(N-1)%26)+s;
        N--;
        N/=26;
    }
    cout<<s;
    return 0;
}