#include <stdio.h>
#include <stdlib.h>
#include <signal.h> //  our new library 
volatile sig_atomic_t flag = 0;

void my_function(int sig){ // can be called asynchronously
  if(sig == 3){
      printf("signal is %d \n",sig);
      printf("my invoke myfuinction start\n");
      flag = 1; // set flag
      printf("my invoke myfuinction end\n");
      exit(sig);
  }else {
     printf("signal is %d \n",sig);
     exit(sig);
  } 
}

int main(){
  // Register signals  
  // auto import by shell script  i2fl.sh
  
  signal(SIGABRT,my_function);
  signal(SIGSEGV,my_function);
  signal(SIGSTKFLT,my_function);
  signal(SIGTTIN,my_function);
  signal(SIGVTALRM,my_function);
  signal(SIGSYS,my_function);
  signal(SIGRTMIN+4,my_function);
  signal(SIGRTMIN+9,my_function);
  signal(SIGRTMIN+14,my_function);
  signal(SIGRTMAX-11,my_function);
  signal(SIGRTMAX-6,my_function);
  signal(SIGRTMAX-1,my_function);
  signal(SIGINT,my_function);
  signal(SIGBUS,my_function);
  signal(SIGUSR2,my_function);
  signal(SIGCHLD,my_function);
  signal(SIGTTOU,my_function);
  signal(SIGPROF,my_function);
  signal(SIGRTMIN,my_function);
  signal(SIGRTMIN+5,my_function);
  signal(SIGRTMIN+10,my_function);
  signal(SIGRTMIN+15,my_function);
  signal(SIGRTMAX-10,my_function);
  signal(SIGRTMAX-5,my_function);
  signal(SIGRTMAX,my_function);
  signal(SIGQUIT,my_function);
  signal(SIGFPE,my_function);
  signal(SIGPIPE,my_function);
  signal(SIGCONT,my_function);
  signal(SIGURG,my_function);
  signal(SIGWINCH,my_function);
  signal(SIGRTMIN+1,my_function);
  signal(SIGRTMIN+6,my_function);
  signal(SIGRTMIN+11,my_function);
  signal(SIGRTMAX-14,my_function);
  signal(SIGRTMAX-9,my_function);
  signal(SIGRTMAX-4,my_function);
  signal(SIGILL,my_function);
  signal(SIGKILL,my_function);
  signal(SIGALRM,my_function);
  signal(SIGSTOP,my_function);
  signal(SIGXCPU,my_function);
  signal(SIGIO,my_function);
  signal(SIGRTMIN+2,my_function);
  signal(SIGRTMIN+7,my_function);
  signal(SIGRTMIN+12,my_function);
  signal(SIGRTMAX-13,my_function);
  signal(SIGRTMAX-8,my_function);
  signal(SIGRTMAX-3,my_function);
  signal(SIGTRAP,my_function);
  signal(SIGUSR1,my_function);
  signal(SIGTERM,my_function);
  signal(SIGTSTP,my_function);
  signal(SIGXFSZ,my_function);
  signal(SIGPWR,my_function);
  signal(SIGRTMIN+3,my_function);
  signal(SIGRTMIN+8,my_function);
  signal(SIGRTMIN+13,my_function);
  signal(SIGRTMAX-12,my_function);
  signal(SIGRTMAX-7,my_function);
  signal(SIGRTMAX-2,my_function);
  
  //      ^          ^
  //  Which-Signal   |-- which user defined function registered
  while(1)  
    if(flag){ // my action when signal set it 1
        printf("\n Signal caught!\n");
        printf("\n default action it not termination!\n");
        flag = 0;
    }     
  return 0;
}
