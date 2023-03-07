#include<stdio.h>
#include<stdlib.h>

void f1(){
  puts("f1");
}

void f2(){
  puts("f2");
}

void f3(){
  puts("f3");
}

int main(){
  puts("open");
  atexit(f1);
  atexit(f2);
  atexit(f3);
  
  puts("close");
}
