#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
extern char **environ;
int main(int argc,char* argv[]){
     argv[0]="vim";
     argv[1]="/home/zhouhao2/test.txt";
     argv[2]=NULL;
     execve("/usr/bin/vim",argv,environ);
  return 0;
}
