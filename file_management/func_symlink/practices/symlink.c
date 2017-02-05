#include <stdio.h>
#include <unistd.h>

//unlink - delete a name and possibly the file it refers to
int main(){

   int res=symlink("symlink.c","sym");
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }

   res=unlink("symlink.o");
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }

   return 0;
}

