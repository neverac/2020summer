#include <iostream>
#include <time.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

/*int msum(int n)
{
    int sum;
    if(n==1){
        return 1;
    }
    else{
        sum = n + msum(n-1);
    }
    return sum;
}*/

/*long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 1000;
    }
    return result;
}*/

/*long long fastpower(long long base,long long power)
{
    long long result = 1;
    if(power==1){
        return base;
    }
    if(!(power & 1)){
        result = (fastpower(base,power/2)%1000*fastpower(base,power/2)%1000)%1000;
    }
    else{
        result = (fastpower(base,power/2)%1000*fastpower(base,power/2)%1000*fastpower(base,1)%1000)%1000;
    }
    return result;
}

int main()
{
   clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    long long base, power;
    cin >> base >> power;
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << fastpower(base, power) << endl;
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << "the time cost is " << double(finish - start) / CLOCKS_PER_SEC;
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;
}*/


/**
 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
 */
/*long long normalPower(long long base, long long power) {
    long long result = 1;
    for (int i = 1; i <= power; i++) {
        result = result * base;
        result = result % 1000;
    }
    return result % 1000;
}

int main() {
    clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    long long base, power;
    cin >> base >> power;
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << normalPower(base, power) << endl;
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << "the time cost is " << double(finish - start) / CLOCKS_PER_SEC;
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;

}*/

int main()
{
    int N, K;
    cin >>N >>K;
    vector<int> pric(N);
    for(int i=0;i<N;i++){
        cin >>pric[i];
    }
    sort(pric.begin(),pric.end());
    int sum=0;
    for(int i=0;i<K;i++){
        sum+=pric[i];
    }
    cout <<sum<<endl;
    return 0;
}
