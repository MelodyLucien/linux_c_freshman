#include <stdio.h>
#include <unistd.h>

int main(){

   int res=symlink("symlink.c","sym");
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }
   return 0;
}

