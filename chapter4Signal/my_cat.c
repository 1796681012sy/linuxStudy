#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#define LENBUF 1024

int main(int args,char **argv){
  char buf[1024];
  memset(buf,0,sizeof(LENBUF));
  if(args < 2){
    printf("请输入你要看的文件");
    return 0;
    }
  
  //int pf  = open(argv[1],O_WRONLY);
  int pf  = open(argv[1],O_RDONLY);
  
  if(pf < 0){
    perror("open():");
    return 0;
  }
  while(1){
    int len = 0;
    do{
      len = read(pf,buf,LENBUF);
      if(len < 0 ){
	if(errno == EINTR) continue;
	perror("read():");
	exit(1);
      }
    }
    while(len < 0);
    int pos = 0;
    if(len == 0) break;
    while(len > 0){
      int ret = write(STDOUT_FILENO,buf + pos,len);
      if(ret < 0 ){
	if(errno == EINTR) continue;
	perror("write()");
	exit(1);
      }
      pos += ret;
      len -= ret;
    }
   }
  close(pf);
}
