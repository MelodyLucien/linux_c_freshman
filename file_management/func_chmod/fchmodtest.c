#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>

/**
NAME
       chmod, fchmod - change permissions of a file

SYNOPSIS
       #include <sys/stat.h>

       int chmod(const char *path, mode_t mode);
       int fchmod(int fd, mode_t mode);

DESCRIPTION
       These system calls change the permissions of a file.  They differ only in how the file is specified:

       * chmod()  changes the permissions of the file specified whose pathname is given in path, which is dereferenced if it is
         a symbolic link.

       * fchmod() changes the permissions of the file referred to by the open file descriptor fd.

       The new file permissions are specified in mode, which is a bit mask created by ORing together zero or more of  the  fol‐
       lowing:

       S_ISUID  (04000)  set-user-ID (set process effective user ID on execve(2))

       S_ISGID  (02000)  set-group-ID  (set  process  effective  group  ID  on  execve(2);  mandatory  locking, as described in
                         fcntl(2); take a new file's group from parent directory, as described in chown(2) and mkdir(2))

       S_ISVTX  (01000)  sticky bit (restricted deletion flag, as described in unlink(2))

       S_IRUSR  (00400)  read by owner

       S_IWUSR  (00200)  write by owner

       S_IXUSR  (00100)  execute/search by owner ("search" applies for directories, and means that entries within the directory
                         can be accessed)

       S_IRGRP  (00040)  read by group

       S_IWGRP  (00020)  write by group

       S_IXGRP  (00010)  execute/search by group

       S_IROTH  (00004)  read by others

       S_IWOTH  (00002)  write by others

       S_IXOTH  (00001)  execute/search by others

       The  effective UID of the calling process must match the owner of the file, or the process must be privileged (Linux: it
       must have the CAP_FOWNER capability).

       If the calling process is not privileged (Linux: does not have the CAP_FSETID capability), and the  group  of  the  file
       does  not  match  the  effective  group ID of the process or one of its supplementary group IDs, the S_ISGID bit will be
       turned off, but this will not cause an error to be returned.

       As a security measure, depending on the file system, the set-user-ID and set-group-ID execution bits may be  turned  off
       if  a  file is written.  (On Linux this occurs if the writing process does not have the CAP_FSETID capability.)  On some
       file systems, only the superuser can set the sticky bit, which may have a special meaning.  For the sticky bit, and  for
       set-user-ID and set-group-ID bits on directories, see stat(2).

       On  NFS file systems, restricting the permissions will immediately influence already open files, because the access con‐
       trol is done on the server, but open files are maintained by the client.  Widening the permissions may  be  delayed  for
       other clients if attribute caching is enabled on them.

RETURN VALUE
       On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.

**/

int main(){
 int fd =open("tt.txt",O_RDWR);
 if(fd!=-1)
 printf("fd is %d \n successful open a file!!\n",fd);

 fchmod(fd,S_IXUSR|S_IRUSR|S_IWUSR|S_IROTH|S_IRGRP|S_IWGRP|S_IXGRP);

/*
 int res=chmod("tt.txt",S_IXUSR|S_IRUSR|S_IWUSR|S_IROTH|S_IXOTH|S_IWOTH|S_IXGRP|S_IWGRP|S_IRGRP);
 if(res==0){
    printf("on success!!!\n");
 }
*/
 perror("fchmod");

 close(fd);

 return 0;
}
