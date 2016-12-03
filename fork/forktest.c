#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

//this program will print twice hello
int main(){
  pid_t cpid;

  cpid=fork();

  printf("hello\n");
  printf("getpid %ld,getppid %ld\n",(long)getpid(),(long)getppid);
  printf("sizeof long %d\n",(int)sizeof(long));
  printf("sizeof int %d\n",(int)sizeof(int));
  return 0;
}
