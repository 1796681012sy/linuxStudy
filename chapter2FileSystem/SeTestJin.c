#include<stdio.h>
#include<stdlib.h>
int b;

int main(int argsm,char** argv){
  int a;
  printf("%p\n",&argsm);
  int* h = (int*)malloc(10);
   printf("%p\n",h); 
  printf("%p\n",&a); 
  printf("%p",&b);
  getchar();
}
