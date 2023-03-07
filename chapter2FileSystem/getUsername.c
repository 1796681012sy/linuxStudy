#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<pwd.h>

int main(int args,char* argv[]){
  if(args <  2){
    puts("请输入用户编号");
    return 0;
  }
  struct passwd* pwd;
  pwd = getpwuid(atoi(argv[1]));
  if(pwd == NULL){
    puts("不存在");
    return 0;
  }
  puts(pwd->pw_name);
}
