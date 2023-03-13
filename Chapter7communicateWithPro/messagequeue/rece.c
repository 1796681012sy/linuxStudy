#include<stdio.h>
#include<stdlib.h>
#include"proto.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main(){
  key_t key;
  key = ftok(KEYPATH,KEYVA);
  if(key < 0){
    perror("ftok():");
    exit(1);
  }
  struct msg_st msg;
  int id = msgget(key,IPC_CREAT|0660);
  printf("id = %d\n",id);
  if(id < 0){
    perror("msgget():");
    exit(1);
  }
  msg.type = 1;
  //while(1){
    if(msgrcv(id,&msg,sizeof(struct msg_st)-sizeof(long),0,0) < 0){
      perror("msgrcv():");
      exit(1);
    }
    printf("%s\n",msg.s);
    printf("%d\n",msg.chinese);
    printf("%d\n",msg.math);
    //}
  msgctl(id,IPC_RMID,NULL);
  exit(0);
}
