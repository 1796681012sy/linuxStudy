#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int num,char *a[]){
  FILE* fp = fopen(a[1],"r");
  //FILE* fp = fopen("tmp","r");
  
  if(fp == NULL){
    perror("没有文件");
    return 0;
  }
  char* hh =(char*) malloc(10 * sizeof(char));
  int  now = 0,i = 0,bs = 0;
  while(1){
    now = fgetc(fp);
    if(now == '\n' || now == EOF) break;
    hh[bs] = now;
    i++;
    bs++;
    if(i == 10){
      i=0;
      char* newHh =(char*) realloc(hh,10 * sizeof(char));
      if(newHh == NULL){
	perror("太长了，申请失败");
	return 0;
      }
      hh = newHh;
    }
  }
  puts("");
  //printf("%d",bs);
  printf("%s",hh);
}
