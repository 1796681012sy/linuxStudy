#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void print(void* h){
  printf("hello %s\n",h);
}

void* func(void* p){
  puts("func:begin");
  pthread_cleanup_push(print,(void*)"1");
  pthread_cleanup_push(print,(void*)"2");
  pthread_cleanup_push(print,(void*)"3");
  puts("func:end");

  pthread_cleanup_pop(1);
  pthread_cleanup_pop(0);
  pthread_cleanup_pop(1);
  
  pthread_exit(NULL);
}

int main(){
  puts("begin");
  pthread_t tid;
  int err = pthread_create(&tid,NULL,func,NULL);
  if(err){
    printf("pthread_create():%s",strerror(err));
    exit(1);
  }
  pthread_join(tid,NULL);
  puts("end");
}
