#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include "mysem.h"
#define N 4
#define LEFT 100
#define RIGHT 200

struct threadDate{
  int i;
};

struct mysem_str* semp;

void* func(void* );

int main(){
  semp = mysem_init(N);
  if(semp == NULL){
    printf("mysem_init():error");
    exit(1);
  }
  //printf("%d",sizeof(threadDate));
  pthread_t tid[300];
  memset(tid,0,sizeof(tid));
  for(int i=LEFT;i<=RIGHT;i++){
    struct threadDate* p = (struct threadDate*)malloc(sizeof(struct threadDate));
    p->i = i;
    mysem_sub(semp,1);
    int err = pthread_create(tid+i,NULL,func,(void*) p);
    if(err){
      printf("pthread_create():%s",strerror(err));
      exit(1);
    }
   }
  for(int i=LEFT;i<=RIGHT;i++){
    void* p;
    pthread_join(tid[i],&p);
    free((struct threadDate*)p);
  }
  mysem_destroy(semp);
}

void* func(void* p){
  int i = ((struct threadDate*)p)->i;
  int flag = 1 ;
  for(int j=2; j<i/2;j++){
    if(i%j==0) flag = 0;
  }
  //sleep(6);
  if(flag) printf("%d is a prime number\n",i);
  mysem_add(semp,1);
  pthread_exit(p);
}
