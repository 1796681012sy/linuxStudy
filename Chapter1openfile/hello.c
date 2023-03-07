#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int num,char* a[]){
  printf("%d",num);
  for(int i=0;i<num;i++){
    printf("%s\n",a[i]);
  }
}
