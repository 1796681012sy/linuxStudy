#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

jmp_buf e;
/*
  经过测验goto只能在一个函数内跳，在不同函数之间跳的话连编译都过不去。
  longjmp 可以实现函数甚至程序间的跳转,而且不只是改变pc值，函数栈的指针也改变了，
  可以环境完全恢复成了setjmp时候的环境，寄存器，栈，都恢复成了setjmp的时候。
 */
void goitd(int d){
  int dd = 8;
  //goto back;
  longjmp(e,1);
  puts("back D!");
  
}

void goitc(int c){
  int cc = 6;
  goitd(7);
  puts("back C!");
  
}

void goitb(int b){
  int bb = 4;
  int ret = setjmp(e);
  if(ret == 0){
    goitc(5);
  }
  if(ret == 1){
    puts("return to B!");
  }
  puts("back B!");
  /*back:
  bb++;
  puts("hello i am back");*/
}

void goita(int a){
  int aa = 2;
  goitb(3);
  puts("back a!");
}

int main(){
  goita(1);
}
