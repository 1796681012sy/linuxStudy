#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int num,char *a[]){
  FILE* pf = fopen(a[1],"r");
  fseek(pf,0,SEEK_END);
  long ans = ftell(pf);
  printf("%ld",ans);
}
