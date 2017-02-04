#include<stdio.h>
#include<unistd.h>

/**
DESCRIPTION
       chroot()  changes  the  root  directory  of the calling process to that specified in
       path.  This directory will be used for pathnames beginning with /.  The root  direc‐
       tory is inherited by all children of the calling process.

       Only  a  privileged process (Linux: one with the CAP_SYS_CHROOT capability) may call
       chroot().

       This call changes an ingredient in the pathname resolution process and does  nothing
       else.

       This  call does not change the current working directory, so that after the call '.'
       can be outside the tree rooted at '/'.  In particular, the superuser can escape from
       a "chroot jail" by doing:

           mkdir foo; chroot foo; cd ..

       This  call does not close open file descriptors, and such file descriptors may allow
       access to files outside the chroot tree.

**/


int main(){
   int res;
   res=chroot("/home/zhouhao2/linuxc/linux_c_freshman/file_management/func_chown/");
   if(res== -1){
    perror("return error\n");
   }else if(res==0){
     printf("open success!\n");
   }

   return 0;
}
