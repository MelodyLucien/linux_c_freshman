#include <stdio.h>

//rename()  renames a file, moving it between directories if required

int main(){

   int res=rename("test3","../test3");
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }
   return 0;
}

