#include<iostream>
#include<cstdio>
using namespace std;
long long stock[370];
int main(){
	int d;
    scanf("%d",&d);
    long long leave=0;
    long long money=100;
    for (int i=1;i<=d;i++){
        scanf("%lld", &stock[i]); 
    }
	for (int i=1;i<=d-1;i++){
	    int j=i+1;
        while (j<=d&&stock[j]>=stock[j-1])j++;
        j--;
        if (i==j) continue;
        leave = money/stock[i];
        if(leave>100000){
            leave=100000;
        }
        money += leave*(stock[j]-stock[i]);
        i = j;
	}
	cout << money << endl;
}
