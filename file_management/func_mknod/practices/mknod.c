#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

//The  system  call  mknod()  creates  a  file  system node (file, device special file or named pipe) named pathname, with
//attributes specified by mode and dev.

int main(){

   int res=mknod("testdir",S_IFIFO,0);
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }
   return 0;
}

