#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define ll long long
int loop = 1;

void change(int x){
  loop = 0;
}

int main(){
  ll now = 0;
  alarm(5);
  signal(SIGALRM,change);
  while(loop) now++;
  printf("%lld",now);
}
