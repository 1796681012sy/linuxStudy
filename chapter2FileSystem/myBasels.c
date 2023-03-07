#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>

int main(int args,char** argv){
  if(args < 2){
    printf("请输入文件名");
    exit(1);
  }
  DIR* pf = opendir(argv[1]);
  if(pf == NULL){
    perror("opendir");
    exit(1);
  }
  struct dirent* now;
  while(1){
    now = readdir(pf);
    if(now == NULL) break;
    printf("%s\n",now->d_name);
  }
  closedir(pf);
}
