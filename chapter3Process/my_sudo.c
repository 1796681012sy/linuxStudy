#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int args,char** argv){
  if(args < 3){
    puts("请输入你要改用谁的权限");
    return 0;
  }

  int pid = fork();

  if(pid < 0 ){
    perror("fork():");
    return 1;
  }

  if(pid == 0){
    if(setuid(atoi(argv[2])) < 0){
      perror("setuid():");
      exit(1);
    }
    execvp(argv[2],argv + 2);
    perror("execvp():");
    exit(1);
  }
  else{
    wait(NULL);
    return 0;
  }
}
