#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int gvar=5;
int main(){

 int lvar=3;
 pid_t pid;

 printf("i am in process pid=%d\n",getpid());
 printf("the vars before change: gvar = %d,lvar=%d\n",gvar,lvar);

 if((pid = vfork())<0){
   printf("no fork error!");
   exit(1);
 }else if (pid==0){

    gvar--;
    lvar--;

    printf("i am in sub process %d\n",getpid());
    printf("the vars  change: gvar = %d,lvar=%d\n",gvar,lvar);
    _exit(0);
 }else{
    
    printf("i am in father process %d\n",getpid());
    printf("the vars change: gvar = %d,lvar=%d\n",gvar,lvar);
 }
  return 0;
}
