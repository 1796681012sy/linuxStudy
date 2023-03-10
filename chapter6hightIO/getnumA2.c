#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


int main(int args,char** argv){
  if(args < 2){
    perror("args():");
    exit(1);
  }
  int fd = open(argv[1],O_RDWR|O_APPEND);
  if(fd < 0 ){
    perror("open():");
    exit(1);
  }
  struct stat sta;
  fstat(fd,&sta);
  off_t sz = sta.st_size;
  char* star = NULL;
  star = (char*)mmap(NULL,sz,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  if(star < 0){
    perror("mmap");
    exit(1);
  }
  close(fd);
  int cout = 0;
  for(int i = 0; i < sz ;i++){
    if(*(star + i) == 'a') cout ++;
  }
  printf("%d\n",cout);
  for(int i = 0; i < sz ;i++){
    if(*(star + i) == 'a') *(star + i) = 'b';
  }
  munmap(star,sz);
}
