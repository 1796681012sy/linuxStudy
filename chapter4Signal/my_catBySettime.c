#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
#include<sys/time.h>
#define LENBUF 5

int loop = 1;
void handalrm(int x){
  loop = 0;
  //alarm(1);
}

int main(int args,char **argv){
  //alarm(1);
  struct itimerval it;
  it.it_interval.tv_sec = 1;
  it.it_interval.tv_usec = 0;
  it.it_value.tv_sec = 1;
  it.it_value.tv_usec = 0;
  
  if(setitimer(ITIMER_REAL,&it,NULL) < 0){
    perror("setitimer():");
    exit(1);
  }
  signal(SIGALRM,handalrm);
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
    while(loop) pause();
    loop = 1;
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
