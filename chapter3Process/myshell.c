#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glob.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void printHello(){
  printf("hello!you can ask me to do something:");
}

struct my_glob{
  glob_t globres;
};

void parse(char* s,struct my_glob* m){

  char* ans;int i = 0;
  while(1){
     ans = strsep(&s," \n\t");
     if(ans == NULL) break;
     if(ans[0] == '\0') continue;
     int x = glob(ans,GLOB_NOCHECK|GLOB_APPEND*i,NULL,&(m->globres));
     i = 1;
     if(x!=0){
       printf("glob");
       exit(1);
     }
    }
}

int main(){

  struct my_glob m;
  while(1){

    printHello();
    char* s = NULL;
    size_t n = 0;
    int nn = getline(&s,&n,stdin);
    if(nn < 0){
      free(s);
      perror("gteline():");
      exit(0);
    }
    parse(s,&m);
    if(0){//内部命令
      
    }
    else{
      int pid = fork();
      if(pid < 0){
	perror("fork()");
	exit(1);
      }
      if(pid == 0){
	execvp(m.globres.gl_pathv[0],m.globres.gl_pathv);
	perror("execvp()");
	exit(1);
      }
      else{
	wait(NULL);
      }
    }
    //printf("%d %s\n",n,s);
  }
}
