#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
int main(){
  time_t s5= time(NULL) + 5;
  ll now = 0;
  while(time(NULL) < s5){
    now++;
  }
  printf("%lld",now);
}
