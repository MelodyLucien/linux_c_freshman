#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

//rmdir() deletes a directory, which must be empty


int main(){

   int res=rmdir("testdir");
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }

   res=mkdir("testdir",0222);

   if(res==1){
       perror("create failed!");
   }else{
       perror("create success!");
   }


   return 0;
}

