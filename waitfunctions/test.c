#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t cpid, w,fatherid;
    int status;

    fatherid=getpid();
    printf("my pid is %d groupid is %d\n",getpid(),getpgid(fatherid));
    cpid=fork();
    if(cpid==0){
       printf("my pid is %d groupid is %d\n",getpid(),getpgid(fatherid));
       pause();
    }
    return 0;
}
