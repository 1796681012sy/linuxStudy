#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


static int getsz(const char* s){
  struct stat buf;
  if(stat(s,&buf)<0){
    perror("异常：");
    exit(1);
  }
  int sz = buf.st_size;
  return sz;
}

int main(int argc,char* argv[]){
  if(argc < 2){
    fprintf(stderr,"请输入文件名");
    return 0;
  }
  int sz = getsz(argv[1]);

  printf("%d",sz);
  
}
