#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
/**

NAME
       chdir, fchdir - change working directory

SYNOPSIS
       #include <unistd.h>

       int chdir(const char *path);
       int fchdir(int fd);

DESCRIPTION
       chdir() changes the current working directory of the calling process to the directory specified in path.

       fchdir() is identical to chdir(); the only difference is that the directory is given as an open file descriptor.

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.

ERRORS
       Depending on the filesystem, other errors can be returned.  The more general errors for chdir() are listed below:

       EACCES Search permission is denied for one of the components of path.  (See also path_resolution(7).)

       EFAULT path points outside your accessible address space.

       EIO    An I/O error occurred.

       ELOOP  Too many symbolic links were encountered in resolving path.

       ENAMETOOLONG
              path is too long.

       ENOENT The file does not exist.

       ENOMEM Insufficient kernel memory was available.

       ENOTDIR
              A component of path is not a directory.

       The general errors for fchdir() are listed below:

       EACCES Search permission was denied on the directory open on fd.

       EBADF  fd is not a valid file descriptor.

CONFORMING TO
       SVr4, 4.4BSD, POSIX.1-2001.

NOTES
       The current working directory is the starting point for interpreting relative pathnames (those not starting with '/').

       A child process created via fork(2) inherits its parent's current working directory.  The current working directory is left unchanged by execve(2).


**/
void printOnResult(int res,const char * msg){
    printf(msg);
    printf("\n");
   if(res==0){
       printf("success,the return value is %d\n",res);
   }else if(res==-1){
       printf("error,the return value is %d\n",res);
   }
}

int main(){

    // sysbolic link return -1 can not acess
   int res=access("./test.txt",F_OK);

   printOnResult(res,"access file /home/zhouhao2/linux_c_freshman/file_management/func_chdir/test/test.txt");

   int res1=chdir("test");

   printOnResult(res1,"chdir to test");

   int res1_2=access("./test.txt",F_OK);

   printOnResult(res1_2,"access file under test");

   return 0;
}
