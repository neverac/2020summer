#include <iostream>
using namespace std;
long long a[100005];
int main(){
    int N;
    cin >> N ;
    long long result = 0;
    while(N--){
        int b;
        cin >> b;
        a[b]++;
        result += b;
    }

    cin >> N;
    while(N--){
        int p,q;
        cin >> p >> q;
        if(a[p]){
            a[q]+=a[p];
            result += a[p]*(q-p);
            a[p]=0;
        }
        cout << result << endl ;
    }
    return 0;
}