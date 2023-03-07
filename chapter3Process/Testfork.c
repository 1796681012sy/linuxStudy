#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
  printf("open by %d\n",getpid());
  fflush(NULL);
  pid_t pid = fork();
  if( pid < 0 ){
    perror("fork():\n");
    exit(1);
  }
  if( pid == 0){
    printf("子程序 %d\n",getpid());
  }
  if( pid > 0){
    printf("父程序 %d\n",getpid());
  }

  printf("close by %d\n",getpid());
  return 0;
}
