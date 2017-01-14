#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
extern char **environ;

/**
 execve() executes the program pointed to by filename.  filename must be either a binary executable, or a script starting
       with a line of the form:

           #! interpreter [optional-arg]

       For details of the latter case, see "Interpreter scripts" below.

       argv is an array of argument strings passed to the new program.  By convention, the first of these strings  should  con‐
       tain  the  filename  associated  with  the file being executed.  envp is an array of strings, conventionally of the form
       key=value, which are passed as environment to the new program.  Both argv and envp must be terminated by a NULL pointer.
       The argument vector and environment can be accessed by the called program's main function, when it is defined as:

           int main(int argc, char *argv[], char *envp[])

       execve()  does  not return on success, and the text, data, bss, and stack of the calling process are overwritten by that
       of the program loaded.

       If the current program is being ptraced, a SIGTRAP is sent to it after a successful execve().


**/
int main(int argc,char* argv[]){
  printf("before i execve()\n");
  pid_t pid;
  if((pid=fork())<0){
      printf("fork failed!!!\n");
  }else if(pid==0){
     execve("new",argv,environ);
  }else if(pid>0){
     printf("i am in the father process!!\n");
  }
  return 0;
}
