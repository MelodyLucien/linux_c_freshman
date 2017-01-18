#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
/**
      #include <unistd.h>

       int access(const char *pathname, int mode);

      access()  checks  whether the calling process can access the file path‐
       name.  If pathname is a symbolic link, it is dereferenced.

      The mode specifies the accessibility check(s) to be performed,  and  is
       either the value F_OK, or a mask consisting of the bitwise OR (按位或)of one or
       more of R_OK, W_OK, and X_OK.  F_OK tests  for  the  existence  of  the
       file.   R_OK,  W_OK,  and  X_OK test whether the file exists and grants
       read, write, and execute permissions, respectively.

       The check is done using the calling process's real UID and GID,  rather
       than the effective IDs as is done when actually attempting an operation
       (e.g., open(2)) on the file.  This allows set-user-ID programs to  eas‐
       ily determine the invoking user's authority.

       If the calling process is privileged (i.e., its real UID is zero), then
       an X_OK check is successful for a regular file if execute permission is
       enabled for any of the file owner, group, or other.

       RETURN VALUE
       On  success  (all requested permissions granted, or mode is F_OK and the file exists), zero is returned.  On error (at least one bit in mode asked for a permis‐
       sion that is denied, or mode is F_OK and the file does not exist, or some other error occurred), -1 is returned, and errno is set appropriately.
**/
int main(){

    // sysbolic link return -1 can not acess
   int res=access("/home/zhouhao2/linux_c_freshman/file_management/func_ascces/test",F_OK);

   //int res1=access("/home/zhouhao2/mycode/myGithub/linux_c_freshman/file_management/func_access/test",F_OK);

   int res1=access("/home/zhouhao2/mycode/myGithub/linux_c_freshman/file_management/func_access/test",R_OK|W_OK);

   if(res1==0){
       printf("success,the return value is %d\n",res1);
   }else if(res1==-1){
       printf("error,the return value is %d\n",res1);
   }

   return 0;
}
