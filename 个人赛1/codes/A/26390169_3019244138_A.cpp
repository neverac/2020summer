#include <iostream>
#include <algorithm>
using namespace std;
int MIN(int a, int b){
    return a<b;
}
int list[1005];
int main(){
    int N, K;
    cin >> N >> K ;
    for(int i = 0 ; i < N ; i++ ){
        cin >> list[i] ;
    }
    sort(list,list+N,MIN);
    int result = 0 ;
    for(int i = 0 ; i < K ; i++ )
    result += list[i];
    cout << result << endl ;

    return 0;
}