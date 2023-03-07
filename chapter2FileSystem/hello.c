#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define OPENFILE "tmp" 

int main(){
  //close(1);
  int fp1 = open(OPENFILE,O_WRONLY|O_CREAT|O_TRUNC,0777);
  close(1);
  dup(fp1);
  //close(fp1);
  puts("hello");
  //printf("1111");
}
