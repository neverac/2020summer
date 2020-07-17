#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int fruit[1005];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>fruit[i];
    }
    sort(fruit,fruit+n);
    int sum = 0;
    for(int i = 0; i < k; i++ ){
        sum += fruit[i];
    }
    cout<<sum<<endl;
    return 0;
}

