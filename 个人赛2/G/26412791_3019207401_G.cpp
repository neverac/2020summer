#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,maxx,minn;
    cin>>n>>k;
    vector<int> ans;
    maxx=n;
    minn=1;
    for(int i=0;i<k;i++){

        if(i%2==0){
            ans.push_back(minn);
            minn++;
        }
        else {
            ans.push_back(maxx);
            maxx--;
        }
    }
    for(int i=0;i<n-k;i++){
        if(k%2==0){
            ans.push_back(maxx);
            maxx--;
        }else {
           ans.push_back(minn);
            minn++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
