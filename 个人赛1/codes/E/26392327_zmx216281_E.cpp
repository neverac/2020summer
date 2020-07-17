#include<iostream>
#include<stack>
using namespace std;
int ans[100];
int main(){
    long long N;
    while(~scanf("%lld",&N)){
        int temp = 0;
        while(N){
            ans[temp++]=(N-1)%26;
            N--;
            N/=26;
        }
        for(int i=temp-1;i>=0;i--){
            cout << (char)('a'+ans[i]);
        }
        cout << endl;
    }
}