#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include "mysem.h"


struct mysem_str{
  int value;
  pthread_mutex_t mut;
  pthread_cond_t cond;
};

mysem_t* mysem_init(int val){
  struct mysem_str* p ;
  p = malloc(sizeof(struct mysem_str));
  if(p == NULL) return p;
  p->value = val;
  pthread_cond_init(&(p->cond),NULL);
  pthread_mutex_init(&(p->mut),NULL);
  return p;
}

int mysem_add(mysem_t* pp,int n){
  struct mysem_str* p = pp;
  pthread_mutex_lock(&(p->mut));
  p->value += n;
  pthread_cond_broadcast(&(p->cond));
  pthread_mutex_unlock(&(p->mut));
  return n;
}

int mysem_sub(mysem_t* pp,int n){
  struct mysem_str* p = pp;
  pthread_mutex_lock(&(p->mut));
  while((p->value) < n){
    pthread_cond_wait(&(p->cond),&(p->mut));
  }
  p->value -= n;
  pthread_mutex_unlock(&(p->mut));
  return n;
}

int mysem_destroy(mysem_t* pp){
  struct mysem_str* p = pp;
  pthread_mutex_destroy(&(p->mut));
  pthread_cond_destroy(&(p->cond));
  free(p);
  return 0;
}
