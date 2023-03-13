#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#define PATH "tmp"
#define MPID 21

int id;

void P(){
  struct sembuf s;
  s.sem_num = 0;
  s.sem_op = -1;
  s.sem_flg = 0;
  while(semop(id,&s,1) < 0 ){
    if(errno != EINTR || errno != EAGAIN){
      perror("semop():");
      semctl(id,0,IPC_RMID);
      exit(1);
    }
  }
}

void V(){
  struct sembuf s;
  s.sem_num = 0;
  s.sem_op = 1;
  s.sem_flg = 0;
  if(semop(id,&s,1) < 0 ){
    perror("semop():");
    semctl(id,0,IPC_RMID);
    exit(1);
  }
}

void doit(){
  FILE* f = fopen(PATH,"r+");
  if(f == NULL){
    perror("fopen()");
    exit(1);
  }
  P();
  int num = 0;
  fscanf(f,"%d",&num);
  fseek(f,0,SEEK_SET);
  num++;
  fprintf(f,"%d",num);
  fflush(f);
  V();
  fclose(f);
  exit(0);
}

int main(){

  id = semget(IPC_PRIVATE,1,0600);

  if(semctl(id,0,SETVAL,1) < 0){
    perror("semctl:()");
    exit(1);
  }
  
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
  semctl(id,0,IPC_RMID);
  exit(0);
}
