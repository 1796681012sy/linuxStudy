#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#define MAXLEN 1024

#define PATH "test"
//#define PATH "hello"

int myDu(const char* nPath){
  struct stat nFile;
  if(stat(nPath,&nFile) < 0){
    perror(nPath);
    exit(1);
  }
  if(!S_ISDIR(nFile.st_mode)){
    return nFile.st_blocks;
  }
  else{
    //printf("是文件");
    char toPath[MAXLEN],child[MAXLEN];
    memset(toPath,0,sizeof(toPath));
    memset(child,0,sizeof(child));
    strcpy(toPath,nPath);
    //strcat(toPath,"*");
    DIR* toFf = opendir(toPath);
    long long sz = 0;
    while(1){
      struct dirent* toF = readdir(toFf);
      if(toF == NULL) break;
      char* toName = toF->d_name;
      if((strcmp(toName,".") == 0) || (strcmp(toName,"..") == 0)) continue;
      strcpy(child,nPath);
      int n = strlen(nPath);
      if(toPath[n-1] != '/') strcat(child,"/");
      strcat(child,toName);
      sz += myDu(child);
    }
    sz += nFile.st_blocks;
    return sz;
   }
}

int main(){
  int sz = myDu(PATH);
  printf("%d",sz/2);
}
