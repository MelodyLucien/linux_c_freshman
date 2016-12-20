#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
 pid_t pid;
 if((pid=fork())<0){
   printf("no fork error!");
   exit(1);
 }else if (pid==0){
    printf("i am in sub process %d\n",pid);
 }else{
    printf("i am in father process\n");
 }
  return 0;
}
