#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int num,char* a[]){
  //printf("%d",num);
  /*for(int i=0;i<num;i++){
    printf("%s\n",a[i]);
    }*/
  /*FILE* t = fopen("tmp","r");
  if((t == NULL)){
    perror("");
    return 0;
    }*/
  FILE* sr = fopen(a[1],"r");
  FILE* aim = fopen(a[2],"w");
  printf("%d\n",num);
  printf("%s\n",a[1]);
  printf("%s\n",a[2]);
  if((sr == NULL)||(aim == NULL)){
    perror("");
    return 0;
  }
  int now;
  while(1){
    now = fgetc(sr);
    printf("%c",now);
    if(now == EOF){
      break;
    }
    fputc(now,aim);
  }

  fclose(sr);
  fclose(aim);
}
