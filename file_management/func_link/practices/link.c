#include <stdio.h>
//       link() creates a new link (also known as a hard link) to an existing file.

//       If newpath exists it will not be overwritten.

//       This  new  name may be used exactly as the old one for any operation; both names refer to the same file (and so have the
//       same permissions and ownership) and it is impossible to tell which name was the "original"

int main(){

   int res=link("original","original2");
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }
   return 0;
}

