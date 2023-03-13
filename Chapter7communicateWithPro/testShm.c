#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  int id = shmget(IPC_PRIVATE,1024,0600);
  //printf("id = %d\n",id);
  if( id < 0){
    perror("shmget()");
    exit(1);
  }
  pid_t pid = fork();
  if(pid == 0){
    void* s = shmat(id,NULL,0);
    //printf("id = %d\n",id);
    if(s < 0){
      perror("shmat():");
      exit(1);
    }
    char* ss =(char*)s;
    strcpy(ss,"HELLO!!!");
    shmdt(s);
    exit(0);
  }
  else{
    wait(NULL);
    void* s = shmat(id,NULL,0);
    if(s < 0){
      perror("shmat():");
      exit(1);
    }
    char* ss =(char*)s;
    printf("%s",ss);
    shmdt(s);
    shmctl(id,IPC_RMID,NULL);
    exit(0);
  }
}
