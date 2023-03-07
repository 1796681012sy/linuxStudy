#include<stdlib.h>
#include<stdio.h>
#include<glob.h>
#define PATH "./*"

int main(){

  glob_t ans;
  int err = glob(PATH,0,NULL,&ans);
  if(err < 0){
    printf("err=%d\n",err);
    exit(1);
  }
  for(size_t i=0;i<ans.gl_pathc;i++){
    puts(ans.gl_pathv[i]);
  }
  globfree(&ans);
}
