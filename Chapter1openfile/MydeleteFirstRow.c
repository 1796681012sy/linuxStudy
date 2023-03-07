#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
/*
 这个代码是为了将一个文件的第三行的内容放到第二行
*/

int main(){
  FILE* fp1 = fopen("tmp","r");
  FILE* fp2 = fopen("tmp","r+");
  if(fp1 == NULL){
    perror("文件打开有问题");
    return 0;
  }
  int rpos = 0, wpos = 0,pos = 0;
  int row = 1;
  while(1){
    char c = fgetc(fp1);
    pos++;
    if(c == '\n') row ++;
    if(row == 3){
      fgetc(fp1);
      rpos = pos;
      break;
    }
  }
  row = 1,pos = 0;
  while(1){
    char c = fgetc(fp2);
    pos++;
    if(c == '\n') row ++;
    if(row == 2){
      fgetc(fp1);
      wpos = pos;
      break;
    }
  }
  fseek(fp1,rpos,SEEK_SET);
  fseek(fp2,wpos,SEEK_SET);
  int poss = 0;
  while(1){
    char c = fgetc(fp1);
    if(c == EOF) {
      break;
    }
    int x = ftell(fp2);
    char wnow = fgetc(fp2);
    fseek(fp2,-1,SEEK_CUR);
    fputc(c,fp2);
    poss++;
  }
  int zzz = ftell(fp2);
  int f2 = fileno(fp2);
  
  int trun_num = lseek(f2,0,SEEK_CUR);
  ftruncate(f2,zzz);
  fclose(fp1);
  fclose(fp2);
  
}
