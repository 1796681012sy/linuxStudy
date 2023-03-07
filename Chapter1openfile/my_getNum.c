#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int num,char* a[]){
  FILE* pf = fopen(a[1],"r");
  if(pf == NULL){
    perror("my_getNum");
    exit(1);
  }
  int count = 0;
  while(fgetc(pf) != EOF){
    count++;
  }
  printf("%d\n",count);
  fclose(pf);
}
