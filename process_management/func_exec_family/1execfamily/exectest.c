#include<stdio.h>
#include<unistd.h>

int main(){

   char *args[]={"ls","/",NULL};
   //1.execv
   //execv("/bin/ls",args);

   //2.execve
   //execve("/bin/ls",args,NULL);


   char *args_cvp[]={"ls","/"};

   //3.execvp
   //execvp("ls",args_cvp);

   //4.execl
   //execl("/bin/ls","ls","/",NULL);

   //5.execlp
   //printf("execlp");
   //execlp("ls","ls","/",(char*)NULL);

   //6.execvpe
   execvpe("ls",args,NULL);

   return 0;
}
