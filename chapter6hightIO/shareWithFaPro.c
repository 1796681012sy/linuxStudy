#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAXSZ 1024

int main(){
  char* star = NULL;
  star = (char*) mmap(NULL,MAXSZ,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
  if(star < 0){
    perror("mmap():");
    exit(1);
  }
  pid_t pid = fork();
  if(pid < 0){
    perror("fork()");
    exit(1);
  }
  if(pid == 0){
    strcpy(star,"HELLO");
    munmap(star,MAXSZ);
    exit(0);
  }
  else{
    wait(NULL);
    puts(star);
    exit(0);
  }
}
