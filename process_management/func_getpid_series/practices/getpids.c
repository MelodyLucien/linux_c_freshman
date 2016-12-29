       #include <sys/types.h>
       #include <stdio.h>
       #include <unistd.h>
       #include <stdlib.h>

       pid_t getpid(void);
       pid_t getppid(void);
       int getdtablesize(void);

       void print(char * tag){
         printf("%s current pid is :%d,ppid is:%d \n",tag,getpid(),getppid());
         printf("%s current max fds the process can hold is:%d\n",tag,getdtablesize());
         printf("%s pgid (getpgid()) the process can hold is:%d\n",tag,getpgid(getpid()));
         printf("%s pgid (getpgrp()) the process can hold is:%d\n",tag,getpgrp());
       }

       int main(){
         print("Parent");
         setpgid(getpid(),11990);
         printf("after set pgid (setpgid()) the process's gid is %d\n",getpgrp());
         if(fork()==0){
              print("child");
             _exit(0);//if parent process does't deal with the signal ,this process will be defunct,and the following print will not work.
              printf("child process exit\n");
         }else{
         while(1){
           ;
          }
         }
       }
