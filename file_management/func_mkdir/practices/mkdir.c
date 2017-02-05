#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){

//the permissions of the created directory are (mode & ~umask & 0777)
//The newly created directory will be owned by the effective user ID of the process.
//If the directory containing the file has the set-group-ID bit set,
//or if the file system is mounted with BSD group semantics (mount -o bsdgroups or,  synony‐
//mously  mount  -o grpid), the new directory will inherit the group ownership from its parent;
//otherwise it will be owned by the effective group ID of the process.
//If the parent directory has the set-group-ID bit set then so will the newly created directory

   int res=mkdir("testdir",0222);
   if(res==1){
       perror("failed!");
   }else{
       perror("success!");
   }
   return 0;
}

