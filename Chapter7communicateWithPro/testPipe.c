#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
  int pf[2];
  int err = pipe(pf);
  char buf[10];
  if(err < 0){
    perror("pipe()");
    exit(1);
  }
  pid_t pid = fork();
  if(pid < 0){
    perror("fork()");
    exit(1);
  }
  if(pid == 0){
    /*close(pf[1]);
    int len = read(pf[1],buf,6);
    printf("%s\n",buf);*/
    close(pf[0]);
    write(pf[1],"HELLO",6);
    close(pf[1]);
    exit(0);
  }else{
    /*close(pf[0]);
    write(pf[1],"HELLO",6);
    close(pf[1]);*/
    close(pf[1]);
    int len = read(pf[0],buf,6);
    printf("%s\n",buf);
    close(pf[0]);
    wait(NULL);
    exit(0);
  }
}
