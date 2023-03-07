#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define MAX_NUM 1024
using namespace std;

int main(int argc,char* argv[]){

  int f,s;
  f = open(argv[1],O_RDONLY);
  s = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0777);
  //f = open("tmp",O_RDONLY);
  //s = open("tmp3",O_WRONLY|O_CREAT|O_TRUNC,0777);
  
  char* buf = (char*)malloc(1024 * sizeof(char));
  int count = MAX_NUM;

  if( f < 0){
    perror("第一个文件没打开");
    return 0;
  }
  
  if( s < 0){
    perror("第二个文件有问题");
    return 0;
  }

  while(1){
    int len = read(f,buf,count);
    if(len < 0){
      perror("读第一个文件有问题");
      return 0;
    }
    else if( len == 0){
      break;
    }
    else{
      int len2 = write(s,buf,len);
      if(len2 < 0){
	perror("写出了问题");
	return 0;
      }
    }
  }
  
  close(f);
  close(s);
  free(buf);
}
