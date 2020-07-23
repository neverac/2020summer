#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    char op;
    int p[101];
    for(int i=0;i<n;i++){
        cin >>op;
        if(op=='-'){
            p[i]=-1;
        }
        else{
            p[i]=1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+p[i]<0){
            continue;
        }
        else{
            sum += p[i];
        }
    }
    cout <<sum<<endl;
    return 0;
}
