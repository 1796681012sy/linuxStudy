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
  
  for(int i=1 ; i < 11 ;i++){
    write(1,"*",1);
    sleep(1);
  }
}
