#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

void printit(const int args, char** argv,const struct tm* t){
  while(1){
    int c = getopt(args,argv,"ymdh:msz");
    if(c < 0) break;
    if(c == 'y') {printf("%d ",t->tm_year+1900);}
    
    if(c == 'm') {printf("%d ",t->tm_mon+1);}
    
    if(c == 'd') {printf("%d ",t->tm_mday);}
    
    if(c == 'h') {
      if(strcmp(optarg,"12") == 0){
	if(t->tm_hour > 12) printf("%d ",t->tm_hour - 12);
	else printf("%d ",t->tm_hour);
      }
      else if(strcmp(optarg,"24") == 0) printf("%d ",t->tm_hour);
    }
    
    if(c == 'z') {printf("%d ",t->tm_min);}
    
    if(c == 's') {printf("%d ",t->tm_sec);}
  }
  puts("");
}

int main(int args,char** argv){
  time_t tt = time(NULL);
  struct tm* t = localtime(&tt);
  long long add = 24*60*60*100;
  tt+=add;
  t = localtime(&tt);
  printit(args,argv,t);
  //printf("%d %d %d %d %d %d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
  return 0;
}
