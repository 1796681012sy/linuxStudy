#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define ll long long


int main(){
  for(ll i = 300000000;i < 300000200; i++){
    ll now = i,flag = 1;
    for(ll j = 2;j*j<=i;j++){
      if(now%j == 0) flag = 0; 
    }
    if(flag) printf("%lld\n",now);
  }
  exit(0);
}
