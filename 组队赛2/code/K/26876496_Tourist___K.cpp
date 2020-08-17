#include<bits/stdc++.h>
using namespace std;
multiset<int>  heap; //定义堆
int n,i,j,x,sum,sum1;
int main(){
    int t;
    cin >> t;
    while (t--) {
        sum1= sum = 0;
        heap.clear();
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> x;
            heap.insert(x);
        }
        for (i = 1; i <= n - 1; i++) {
            sum1 = *heap.begin();
            heap.erase(heap.begin());
            sum1 += *heap.begin();
            heap.erase(heap.begin());
            sum += sum1;
            heap.insert(sum1);
        }
        cout << sum << endl;
    }
}