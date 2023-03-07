#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#define PATH "tmp"
#define MAXBUF 1024

int main(){
  FILE* pf;struct tm * tmt;
  pf = fopen(PATH,"a+");
  if(pf == NULL){
    perror("fopen()");
    return 0;
  }
  int count = 0;
  char buff[MAXBUF];
  while((fgets(buff,MAXBUF,pf) != NULL)){
    count++;
  }
  while(1){
    time_t t= time(NULL);
    tmt = localtime(&t);
    fprintf(pf,"%d:%d-%d-%d %d,%d,%d\n",++count,tmt->tm_year+1900,tmt->tm_mon+1,tmt->tm_mday,tmt->tm_hour,tmt->tm_min,tmt->tm_sec);
    fflush(pf);
      sleep(1);
  }
  fclose(pf);
}
