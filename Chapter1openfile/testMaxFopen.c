#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(){
  
  FILE* fp = NULL;
  int count = 0;
  while(1){
    fp = fopen("tmp","r");
    if(fp == NULL){
      perror("testFopen");
      break;
    }
    count++;
  }  
  puts("ok");
  printf("count=%d\n",count);
  return 0;
  
}
