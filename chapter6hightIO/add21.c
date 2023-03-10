#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define PATH "tmp"
#define MPID 21

void doit(){
  FILE* f = fopen(PATH,"r+");
  if(f == NULL){
    perror("fopen()");
    exit(1);
  }
  int fd = fileno(f);
  int err = lockf(fd,F_LOCK,0);
  if(err < 0){
    perror("lockf():");
    exit(1);
    }
  int num = 0;
  fscanf(f,"%d",&num);
  fseek(f,0,SEEK_SET);
  num++;
  fprintf(f,"%d",num);
  fflush(f);
  lockf(fd,F_ULOCK,0);
  fclose(f);
  exit(0);
}

int main(){
  
  for(int i = 0 ;i < MPID; i++){
    int pid = fork();
    if(pid < 0){
      perror("fork()");
      exit(1);
    }
    if(pid == 0){
      doit();
    }
  }
  for(int i=0; i<MPID ;i++)
    wait(NULL);
  exit(0);
}
