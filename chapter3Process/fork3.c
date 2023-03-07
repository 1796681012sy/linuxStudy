#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#define ll long long


int main(){
  /*for(int n = 0;n < 3 ;n++){
     pid_t pid = fork();
     if(pid < 0 ){
      perror("fork()");
      exit(1);
    }
     if(pid == 0){
       for(ll i = 300000000+n;i < 300000200; i+=3){
	 if(pid == 0){
	   ll now = i,flag = 1;
	   for(ll j = 2;j*j<=i;j++){
	     if(now%j == 0) {flag = 0;} 
	   }
	   if(flag) printf("by%d: %lld\n",n,now);
	   //exit(0);
	 }
       }
       exit(0);
     }
  }
  for(int i=1 ;i<= 3 ;i++ ) wait(NULL); 
  exit(0);*/
  for(int n = 0;n < 3 ;n++){
     pid_t pid = fork();
     if(pid < 0 ){
      perror("fork()");
      exit(1);
    }
     if(pid == 0){
       for(ll i = 300000000+n*66;i <= 300000000 + (n+1)*66; i++){
	 if(pid == 0){
	   ll now = i,flag = 1;
	   for(ll j = 2;j*j<=i;j++){
	     if(now%j == 0) {flag = 0;} 
	   }
	   if(flag) printf("by%d: %lld\n",n,now);
	   //exit(0);
	 }
       }
       exit(0);
     }
  }
  for(int i=1 ;i<= 3 ;i++ ) wait(NULL); 
  exit(0);
}
