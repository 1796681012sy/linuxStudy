#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

 int err = mkfifo("my_fifo",0666);
  if(err < 0){
    perror("mkfifo()");
    exit(1);
  }
  int pf = open("my_fifo",O_RDWR);
  if(pf < 0){
    perror("open()");
    exit(1);
  }
  char buf[10];
  pid_t pid = fork();
  if(pid < 0){
    perror("fork()");
    exit(1);
  }
  if(pid == 0){
    write(pf,"HELLO",6);
    close(pf);
    exit(0);
  }else{
    int len = read(pf,buf,6);
    printf("%s\n",buf);
    close(pf);
    wait(NULL);
    exit(0);
  }
}
