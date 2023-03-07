#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

void* MY_print(void* p){
  puts("this thread is working");
  //return NULL;
  pthread_exit(NULL);
  
}

int main(){
  puts("begin");
  pthread_t tid;
  int err = pthread_create(&tid,NULL,MY_print,NULL);
  if(err){
    printf("pthread_create():%s",strerror(err));
  }
  pthread_join(tid,NULL);
  puts("end");
  //sleep(1);
  exit(0);
}
