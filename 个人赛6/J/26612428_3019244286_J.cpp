#include<cstdio>

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  int days = 0;
  int time;
  for(int i = 0; i < n; ++i){
      scanf("%d",&time);
      days += (time+k-1)/k;
  }
  printf("%d\n",(days+1)/2);
}