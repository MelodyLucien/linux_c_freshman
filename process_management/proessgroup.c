#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
 pid_t cpid=getpgrp();
 pid_t childpid;
 printf("my gid %d is \n,my pid is %d\n, my uid is %d\n",cpid,getpid(),getuid());
 if((childpid=fork())==0){
    setpgid(childpid,childpid);
    printf("child 's  pid is %d\n",getpid());
    printf("child 's group id is %d\n",getpgrp());
    pause();
 }
 return 0;
}
