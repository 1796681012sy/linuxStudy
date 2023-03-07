#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

#define PNAM 4
pthread_mutex_t mut[PNAM];

int nextit(int i){
  if( i == 3) return 0;
  return i+1;
}

void* func(void* p){
  int i = (*(int*)p);
  while(1){
    pthread_mutex_lock(mut+i);
    putchar('a'+i);
    pthread_mutex_unlock(mut+nextit(i));
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t tid[PNAM];
  int a[] = {0,1,2,3};
  for(int i = 0; i<PNAM ;i++ ){
    pthread_mutex_init(mut+i,NULL);
    pthread_mutex_lock(mut+i);
    int err = pthread_create(tid+i,NULL,func,a+i);
    if(err){
      printf("pthread_create():%s",strerror(err));
      exit(1);
     }
  }
  alarm(5);
  pthread_mutex_unlock(mut+0);
  for(int i = 0; i<PNAM ; i++){
    pthread_join(tid[i],NULL);
  }
  return 0;
}
