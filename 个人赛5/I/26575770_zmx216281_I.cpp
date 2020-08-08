#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    string s;
    scanf("%d",&t);
    while(t--){
        
        vector<int> ji;
        vector<int> ou;
        cin>>s;
        int rec1,rec2;
        for(int i=0;i<s.length();i++){
            int temp = s[i]-'0';
            if(temp%2){
                ou.push_back(temp);
            }
            else{
                ji.push_back(temp);
            }
        }
        for(rec1=0,rec2=0;rec1<ji.size()&&rec2<ou.size();){
            if(ji[rec1]<ou[rec2]){
                cout << ji[rec1++];
            }
            else{
                cout << ou[rec2++];
            }
        }
        for(;rec1<ji.size();rec1++){
            cout << ji[rec1];
        }
        for(;rec2<ou.size();rec2++){
            cout << ou[rec2];
        }
        cout << endl;
    }
    
}