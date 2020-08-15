#include <iostream>
#include <string>
using namespace std;
string banz;
bool isNum(char x){
    return x>='0'&&x<='9';
}
bool check(){
    string inp;
    cin>>inp;
    long long int num1,num2;
    for(int i=0;i<banz.size();i++){
        if(i>=inp.size()){
            return true;
        }
        if(isNum(banz[i])){
            if(!isNum(inp[i])){
                return false;
            }
            int w=i;
            num1=num2=0;
            while(w<banz.size()&&isNum(banz[w])){
                num1=10*num1+banz[w++]-'0';
            }
            w=i;
            while(w<inp.size()&&isNum(inp[w])){
                num2=10*num2+inp[w++]-'0';
            }
            if(num1!=num2){
                return num1>num2;
            }
        }else{
            if(isNum(inp[i])||banz[i]>inp[i]){
                return true;
            }
            if(banz[i]<inp[i]){
                return false;
            }
        }
    }
    return false;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    cin>>banz;
    while(n--){
        if(check()){
            printf("-\n");
        }else{
            printf("+\n");
        }
    }
    return 0;
}