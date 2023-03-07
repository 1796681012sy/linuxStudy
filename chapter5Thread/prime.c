#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#define LEFT 100
#define RIGHT 200

struct threadDate{
  int i;
};

void* func(void* );

int main(){
  //printf("%d",sizeof(threadDate));
  pthread_t tid[202];
  memset(tid,0,sizeof(tid));
  for(int i=LEFT;i<=RIGHT;i++){
    struct threadDate* p = (struct threadDate*)malloc(sizeof(struct threadDate));
    p->i = i;
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
}

void* func(void* p){
  int i = ((struct threadDate*)p)->i;
  int flag = 1 ;
  for(int j=2; j<i/2;j++){
    if(i%j==0) flag = 0;
  }
  if(flag) printf("%d is a prime number\n",i);
  pthread_exit(p);
}
