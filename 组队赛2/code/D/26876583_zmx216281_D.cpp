#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<string> ve;
string s;
int n;
int main(){
    for(int i=1;i<=3;i++){
        cin >> s;
        if(s!="bubble"&&s!="tapioka"){
            ve.push_back(s);
        }
    }
    if(ve.empty())cout << "nothing" << endl;
    else{
        for(int i=0;i<ve.size();i++){
            if(i!=ve.size()-1){
                cout << ve[i] << " ";
            }
            else{
                cout << ve[i] ;
            }
        }
    }
}