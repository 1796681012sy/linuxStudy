#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int id;

int createProcess(){
  pid_t pid = fork();
  if(pid < 0){
    perror("fork()");
    return -1;
  }
  if(pid > 0 ) exit(0);
  id = open("tmp2",O_RDWR);
  if(id < 0){
    perror("open()");
    return -1;
  }
  dup2(id,0);
  dup2(id,1);
  dup2(id,2);
  // if(id > 2) close(id);
  pid_t pidd = setsid();
  if(pidd < 0 ){
    perror("setsid()");
    return -1;
  }
  chdir("/");
  umask(0777);
  printf("%d\n",pidd);
  
  return 0;
}

int main(){
  //FILE* pf = NULL;
  if(  createProcess()){
    exit(1);
  }
  /*puts("11111");
  pf = fopen("tmp1","w");
  
  if(pf == NULL){
    perror("fopen()2222");
    exit(1);
  }
  
  for(int i=1;;i++){
    fprintf(pf,"%d\n",i);
    fflush(pf);
    sleep(1);
  }
  
  fclose(pf);
  */
  int i = 1;
  while(i){
    i++;
    sleep(1);
    printf("%d\n",i);
    fflush(NULL);
  }
  
}
