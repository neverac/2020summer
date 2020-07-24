#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    getline(cin,s);
    if((s[s.size()-1]-'0'+(s[s.size()-2]-'0')*10)%4==0)
        cout<<4<<endl;
    else cout<<0<<endl;
    return 0;
}