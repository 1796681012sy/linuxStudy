#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void print(int x){
  puts("hello");
}

int main(){

  //signal(SIGINT,SIG_IGN);
  signal(SIGINT,print);
  sigset_t s,o;
  sigemptyset(&s);
  sigaddset(&s,SIGINT);
  sigprocmask(SIG_UNBLOCK,&s,&o);
  for(int j = 1; j < 100;j++){
    sigprocmask(SIG_BLOCK,&s,NULL);
    for(int i=1 ; i < 6 ;i++){
      write(1,"*",1);
      sleep(1);
    }
    puts("");
    //sigprocmask(SIG_UNBLOCK,&s,NULL);
    sigsuspend(&o);
  }
  sigprocmask(SIG_SETMASK,&o,NULL);
}
