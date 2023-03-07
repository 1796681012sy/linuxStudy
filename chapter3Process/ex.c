#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(){

  puts("hello");
  execl("/usr/bin/date","date","+%s",NULL);
  //execl("fork3","fork3",NULL);
  perror("execl():");
  exit(0);
}
