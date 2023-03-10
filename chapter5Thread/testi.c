#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
int i = 0;

void* func(void* p){
  i--;
  pthread_exit(NULL);
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,func,NULL);
  i++;
  printf("%d",i);
  pthread_join(tid,NULL);
}
