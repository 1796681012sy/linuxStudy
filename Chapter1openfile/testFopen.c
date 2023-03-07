#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(){
  FILE* fp = fopen("tmp","r");
  if(fp == NULL){
    perror("testFopen");
    return 0;
  }
  puts("OK!");
  fclose(fp);
  return 0;
  
}
