#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
extern char **environ;
int main(int argc,char* argv[]){
  printf("before i execve()\n");
  pid_t pid;
  if((pid=fork())<0){
      printf("fork failed!!!\n");
  }else if(pid==0){
     execve("new",argv,environ);
  }else if(pid>0){
     printf("i am inn the father process!!\n");
  }
  return 0;
}
