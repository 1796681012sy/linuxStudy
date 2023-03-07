#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define MY_SIG SIGRTMIN+6

void print(int x){
  puts("hello");
}

int main(){

  //signal(SIGINT,SIG_IGN);
  signal(MY_SIG,print);
  sigset_t s,o;
  sigemptyset(&s);
  sigaddset(&s,MY_SIG);
  sigprocmask(SIG_UNBLOCK,&s,&o);
  for(int j = 1; j < 100;j++){
    sigprocmask(SIG_BLOCK,&s,NULL);
    for(int i=1 ; i < 6 ;i++){
      write(1,"*",1);
      sleep(1);
    }
    puts("");
    sigprocmask(SIG_UNBLOCK,&s,NULL);
  }
  sigprocmask(SIG_SETMASK,&o,NULL);
}
