#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalchld(int sig);
void signalstop(int sig);
void signalterm(int sig);
int main(){
 int res;
 if(signal(SIGCHLD,&signalchld)!=SIG_ERR){
    printf("signal child is send!!!,pid=%d,myppid=%d\n",getpid(),getppid());
 }

 if(signal(SIGSTOP,&signalstop)==SIG_ERR){
    printf("signal stop  error!!!\n");
 }

 if(signal(SIGTERM,&signalterm)==SIG_ERR){
    printf("signal term error!!!\n");
 }

 pid_t pid;
 if((pid=fork())<0){
   while(1){
     ;
   }
   printf("no fork error!");
   exit(1);
 }else if (pid==0){
    if(signal(SIGCHLD,&signalchld)!=SIG_ERR){
    printf("signal child is send!!!,pid=%d,myppid=%d\n",getpid(),getppid());
 } 
    printf("i am in sub process %d\n",pid);
 }else{
    printf("i am in father process\n");
 }
  return 0;
}

void signalchld(int sig){
   printf("my child is dead,i am sad!!!\n");
}

void signalstop(int sig){
   printf("signal stop is send\n");
}

void signalterm(int sig){
   printf("signal term is send\n");
}
