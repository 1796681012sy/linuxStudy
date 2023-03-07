#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#define LEFT 100
#define RIGHT 200
#define TNUM 4


void* func(void* );
int num;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cut = PTHREAD_COND_INITIALIZER;

int main(){
  //printf("%d",sizeof(threadDate));
  pthread_t tid[TNUM];
  int a[TNUM];
  for(int i=0;i<TNUM;i++) a[i] = i;
  memset(tid,0,sizeof(tid)); 
  for(int i=0;i<TNUM;i++){
    pthread_create(tid+i,NULL,func,a+i);
  }
  for(int i=LEFT;i<=RIGHT;i++){
    pthread_mutex_lock(&mut);
    while(num!=0){
      pthread_cond_wait(&cut,&mut);
    }
    num = i;
    pthread_cond_signal(&cut);
    pthread_mutex_unlock(&mut);
  }
  pthread_mutex_lock(&mut);
  while(num!=0){
    pthread_cond_wait(&cut,&mut);
  }
  num = -1;
  pthread_cond_broadcast(&cut);
  pthread_mutex_unlock(&mut); 
  for(int i=0;i<TNUM;i++){
    pthread_join(tid[i],NULL);
  }
  pthread_mutex_destroy(&mut);
  pthread_cond_destroy(&cut);
  exit(0);
}

void* func(void* p){
  int id = *((int*)p);
  while(1){
    pthread_mutex_lock(&mut);
    while(num==0){
      pthread_cond_wait(&cut,&mut);
    }
    if(num == -1){
      pthread_mutex_unlock(&mut);
      break;
    }
    int i = num;
    /*if(i == 200){
      i++;
      i--;
      }*/
    num = 0;
    pthread_cond_broadcast(&cut);
    pthread_mutex_unlock(&mut);
    int flag = 1 ;
    for(int j=2; j<i/2;j++){
      if(i%j==0) flag = 0;
    }
    if(flag) printf("[%d]%d is a prime number\n",id,i);
  }
  //printf("%d is exited",id);
  pthread_exit(NULL);
}
