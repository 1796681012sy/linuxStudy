#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int args,char* argv[]){

  if(args < 2){
    fprintf(stderr,"请输入文件名");
    exit(1);
  }
  int pf = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0777);
  if( pf < 0 ){
    perror("open():");
    exit(0);
  }
  lseek(pf,1024*1024,SEEK_SET);
  write(pf,"",1);
  close(pf);
  return 0;
}
