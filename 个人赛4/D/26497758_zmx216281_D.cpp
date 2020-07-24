#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int x,int y){
    if(!y){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}
int main(){
    int T;
    int cas=1;
    int n,a,b;
    cin >> T;
    string s1 = "Iaka";
    string s2 = "Yuwgna";
    while(T--){
        cin >> n >> a >> b;
        cout << "Case #" << cas++ << ": ";
        int temp = gcd(a,b);
        if((n/temp)%2==0) cout << s1 << endl;
        else cout << s2 << endl;
    }
}